//krynn 2001/12/6
//PKPetShop

#include "version.h"
#include <string.h>
#include "char.h"
#include "object.h"
#include "char_base.h"
#include "npcutil.h"
#include "lssproto_serv.h"
#include "pet_skill.h"
#include "readmap.h"
#include "log.h"
#include "enemy.h"
#include "npc_pkpetshop.h"
#include "battle.h"

#ifdef _PKPETSHOP
#define MAXSHOPPET 33

static void NPC_PKPetShop_selectWindow( int meindex, int talker, int num,int select);
void NPC_PKPetShop_BuyMain(int meindex,int talker,int before );
void NPC_PKPetShop_GetPetList(char *argstr,char * argtoken2);
BOOL NPC_PKPetShop_SetNewPet(int meindex,int talker,char *data);
BOOL NPC_PKPetShop_SellNewPet(int meindex,int talker,char *data);

void NPC_PKPetShop_Menu(int meindex,int talker);
int NPC_PKPetShop_GetLimtPetList(int talker,char *argstr,char *token2,int sell);
void NPC_PKPetShop_SellMain(int meindex,int talker,int select);
int NPC_GetSellPetList(int itemindex,int flg,char *argstr,char *argtoken,int select,int sell);
BOOL NPC_AddPetBuy(int meindex, int talker,int petID,int kosuu,double rate);
void NPC_PetStrStr(int petID,double rate,char *name,char *token2, int index);
int NPC_SellPetstrsStr(int itemindex,int flg,double rate,char *argtoken,int select,int sell);
void NPC_LimitPetShop(int meindex,int talker,int select);
void NPC_PKPetShop_ExpressmanCheck(int meindex,int talker);
 

/*--伐□弁    烂聒--*/
enum{
	NPC_PKPETSHOP_WORK_NO 		= CHAR_NPCWORKINT1,
	NPC_PKPETSHOP_WORK_EV 		= CHAR_NPCWORKINT2,
	NPC_PKPETSHOP_WORK_EXPRESS	= CHAR_NPCWORKINT3,
};

		  
typedef struct {
	char	arg[32];
	int		type;
}PKPETSHOP_NPC_Shop;


static PKPETSHOP_NPC_Shop		TypeTable[] = {
	{ "FIST",		0 },
	{ "AXE",		1 },
	{ "CLUB",		2 },
	{ "SPEAR",		3},
	{ "BOW",		4},
	{ "SHIELD",		5},
	{ "HELM",		6 },
	{ "ARMOUR",		7 },
	{ "BRACELET",	8},
	{ "ANCLET",		9 },
	{ "NECKLACE",	10},
	{ "RING",		11},
	{ "BELT",		12},
	{ "EARRING",	13},
	{ "NOSERING",	14},
	{ "AMULET",		15},
	{ "OTHER",		16},
	{ "BOOMERANG",	17},
	{ "BOUNDTHROW",	18},
	{ "BREAKTHROW",	19},
#ifdef _ITEM_TYPETABLE
	{ "DISH",	20},
	{ "METAL",	21},
	{ "JEWEL",	22},
	{ "WARES",	23},
	{ "WBELT",	24},
	{ "WSHIELD", 25},
	{ "WSHOES",	26},
	{ "WGLOVE",	27},
	{ "ANGELTOKEN",	28},
	{ "HEROTOKEN",	29},
#endif	
	{ "ACCESSORY",	30},
	{ "OFFENCE",	40},
	{ "DEFENCE",	50},

};


/*********************************
* 初始
*********************************/
BOOL NPC_PKPetShopInit( int meindex )
{

	char	argstr[NPC_UTIL_GETARGSTR_BUFSIZE];

	/*--正奶皿涩烂--*/
	CHAR_setInt( meindex , CHAR_WHICHTYPE , CHAR_TYPEPKPetShop );
	
	if( NPC_Util_GetArgStr(meindex, argstr, sizeof(argstr)) == NULL ) 
	{
		print("NPC_PKPetShopInit_GetArgStrErr");
		return FALSE;
	}
	if(strstr(argstr,"LIMITSHOP") != NULL) 
	{		/*-  中潸曰毁迕白仿弘--*/
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_NO, 1);
	}
	else
	{
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_NO, 0);
	}
	
	if(strstr( argstr, "EVENT") != NULL) 
	{		/*-  中潸曰毁迕白仿弘--*/
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_EV, 1);
	}
	else
	{
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_EV, 0);
	}

	if(strstr( argstr, "EXPRESS") != NULL) 
	{		/*-扪霜盒白仿弘--*/
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_EXPRESS, 1);
	}
	else
	{
		CHAR_setWorkInt( meindex, NPC_PKPETSHOP_WORK_EXPRESS, 0);
	}
	return TRUE;
}


/*********************************
*   仄井仃日木凶凛及质  
*********************************/
void NPC_PKPetShopTalked( int meindex , int talker , char *szMes ,int color )
{
	char	argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char	buff[1024];
	char	buf2[256];
	char 	token[1024];
	int 	i = 1;
	BOOL	sellonlyflg = FALSE;
	char	sellmsg[1024];

    /* 皿伊奶乩□卞覆仄化分仃  杀允月 */
    if( CHAR_getInt( talker , CHAR_WHICHTYPE ) != CHAR_TYPEPLAYER ) 
	{
    	return;
    }

	/*--  及蟆卞中月井升丹井＂--*/
	if(NPC_Util_isFaceToFace( meindex, talker, 2) == FALSE) 
	{		/* ㄠ弘伉永玉动  及心 */
		if( NPC_Util_CharDistance( talker, meindex ) > 1) return;
	}

    if(NPC_Util_GetArgStr( meindex, argstr, sizeof( argstr)) == NULL)
	{
    	print("NPC_PKPetShopInit_GetArgStrErr");
    	return;
    }

	if( NPC_Util_GetStrFromStrWithDelim( argstr, "sellonly_msg", 
										 token, sizeof( token))
		!= NULL)
	{
		sellonlyflg = TRUE;
		strcpysafe(sellmsg, sizeof( sellmsg), token);
	}

	/*--  涛  丹它奶件玉它卞中仃月井升丹井--*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "buy_msg", 
		buff, sizeof( buff)) != NULL )
	{
	    while(getStringFromIndexWithDelim(buff,",",i,buf2,sizeof(buf2)) != FALSE)
		{
			i++;
			if( strstr( szMes, buf2) != NULL) {
				if( CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_EV) == 0) {
					/*-  中潸曰毁  井升丹井及民尼永弁--*/
					if( CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_NO) == 1) {
						if( sellonlyflg ) {
							NPC_PKPetShop_selectWindow( meindex, talker, 3, -1);
							return;
						}
					}
					else{
						NPC_PKPetShop_selectWindow( meindex, talker, 1, -1);
						return;
					}
				}else{
					if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_NO) == 1) {
						if( sellonlyflg) {
							NPC_PKPetShop_selectWindow( meindex, talker, 3, -1);
							return;
						}
					}else{
						NPC_PKPetShop_selectWindow( meindex, talker, 1, -1);
						return;
					}
		 			return;
		 	 	}
			}
		}
	}
	i=1;

	/*--  涛  月它奶件玉它卞中仃月井升丹井--*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "sell_msg", 
		buff, sizeof( buff)) != NULL )
	{
	    while( getStringFromIndexWithDelim(buff,",", i,buf2,sizeof(buf2))
	     != FALSE )
		{
			i++;
			if(strstr(szMes,buf2) != NULL) {
				NPC_PKPetShop_selectWindow( meindex, talker, 2, -1);
				return;
			}
		}
	}
	i = 1;


	/*--公及职及甲件玄毛仁木月蜕邯匹  仄井仃月--*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "other_msg", 
		buff, sizeof( buff)) != NULL )
	{
	    while(getStringFromIndexWithDelim( buff, ",", i, buf2, sizeof( buf2))
	     !=FALSE)
		{
			i++;
			if(strstr(szMes,buf2) != NULL) {
				/*--甲件玄丢永本□斥--*/
				if(NPC_Util_GetStrFromStrWithDelim( argstr, "hint_msg", 
				token, sizeof( token)) != NULL)
				{
					CHAR_talkToCli( talker, meindex, token, CHAR_COLORWHITE);
					return;
				}
			}
		}	
	}

	/*-  中潸曰毁  井升丹井及民尼永弁--*/
	if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_NO) == 1)
	{
		if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_EV) == 1) 
		{
			if( sellonlyflg) 
			{
				CHAR_talkToCli( talker, meindex, sellmsg, CHAR_COLORWHITE);
				return;
			}
		}
		else
		{	/*--  中潸曰毁  及丢永本□斥--*/
			if( sellonlyflg) 
			{
				NPC_PKPetShop_selectWindow( meindex, talker, 3, -1);
				return;
			}
		}
	}
	else
	{
		if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_EV) == 1) {
			if( sellonlyflg) {
				CHAR_talkToCli( talker, meindex, sellmsg, CHAR_COLORWHITE);
				return;
			}
		}else{
			
			if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_EXPRESS) == 1) {
				NPC_PKPetShop_ExpressmanCheck( meindex, talker);
			}else{ 
				/*--仇仇引匹  凶日隋骚它奶件玉它(丢瓦亘□)  憎--*/
				/*--  中潸曰毁  匹卅仁化  骚及饕卅日丢瓦亘□  憎--*/
				NPC_PKPetShop_selectWindow( meindex, talker, 0, -1);
			}
		}
	}
				
}

static void NPC_PKPetShop_selectWindow( int meindex, int talker, int num,int select)
{

	print("\n NPC_PKPetShop_selectWindow()");
	print("\n num = %d ", num);
	switch( num) {
	  case 0:
		/*--丢瓦亘□    --*/
		/*--由仿丢□正霜曰--*/
		CHAR_send_P_StatusString( talker, CHAR_P_STRING_GOLD);
		
		if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_EXPRESS) == 1 ) 
		{
			if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_NO) ==0 ) 
			{
				NPC_PKPetShop_ExpressmanCheck( meindex, talker);
			}
		}
		else if(CHAR_getWorkInt( meindex, NPC_PKPETSHOP_WORK_NO) == 1) 
		{
		}
		else
		{
		  	NPC_PKPetShop_Menu( meindex, talker);
		}
	  	break;

	  case 1:
	  	/*--  丹    --*/
	  	NPC_PKPetShop_BuyMain( meindex, talker, select);
	  	break;

	  case 2:
	  	/*--  月    --*/
	  	NPC_PKPetShop_SellMain( meindex, talker, select);
	  	break;

	  case 3:
	  	/*--  中潸曰毁  匹允方    --*/
	  	NPC_LimitPetShop( meindex, talker, select);
	  	break;

	}
}



/*-----------------------------------------
 * 弁仿奶失件玄井日忒匀化五凶凛卞裟太请今木月［
 *
-------------------------------------------*/
void NPC_PKPetShopWindowTalked( int meindex, int talkerindex, 
								int seqno, int select, char *data)
{
	/*--       及引歹曰卞中卅中午五反蔽   --*/
	if( NPC_Util_CharDistance( talkerindex, meindex ) > 3) {
		/*--由仿丢□正霜曰--*/
		CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
		return;
	}

	makeStringFromEscaped( data);
	switch( seqno){

	  case CHAR_WINDOWTYPE_WINDOWITEMSHOP_STARTMSG:
		/*--备丢瓦亘□卞  壬允--*/
		/*--  丹--*/
		if(atoi( data) == 1 )	NPC_PKPetShop_selectWindow(meindex, talkerindex, 1, -1);

		/*--  月--*/
		if(atoi( data) == 2)	NPC_PKPetShop_selectWindow(meindex, talkerindex, 2, -1);

		/*--请月--*/
		if(atoi( data) == 3)	return;/*--窒手仄卅中--*/
	
		break;


	  case CHAR_WINDOWTYPE_WINDOWITEMSHOP_BUY_MSG:
		/*--失奶  丞及馨笛--*/
		if(NPC_PKPetShop_SetNewPet(meindex , talkerindex, data) == TRUE) {

			NPC_PKPetShop_selectWindow( meindex, talkerindex, 1, 0);

		}else{
			NPC_PKPetShop_selectWindow( meindex, talkerindex ,0, -1);
		}

		break;


	  case CHAR_WINDOWTYPE_WINDOWITEMSHOP_SELL_MSG:
		/*--失奶  丞及绰轮--*/
		if(NPC_PKPetShop_SellNewPet(meindex , talkerindex, data) == TRUE) {
			NPC_PKPetShop_selectWindow( meindex, talkerindex, 2, 0);

		}else{
			NPC_PKPetShop_selectWindow( meindex,  talkerindex, 0, -1);
		}

		break;
			
	  case CHAR_WINDOWTYPE_WINDOWITEMSHOP_LIMIT:
		 if(select == WINDOW_BUTTONTYPE_YES) {
			NPC_PKPetShop_selectWindow( meindex, talkerindex ,2, -1);

		}else  if(select == WINDOW_BUTTONTYPE_NO) {
			return;
		}else if(select == WINDOW_BUTTONTYPE_OK) {
				NPC_PKPetShop_selectWindow( meindex, talkerindex, 2, -1);
		}
		break;
	
	  case CHAR_WINDOWTYPE_WINDOWITEMSHOP_EXPRESS:
		if(atoi(data) == 2) {
			NPC_PKPetShop_selectWindow( meindex, talkerindex, 1, -1);
		}else if(atoi( data) == 4) {
			NPC_PKPetShop_selectWindow( meindex, talkerindex, 2, -1);
		}
	}
}


/*-----------------------------------------
 *
 *  丹质  丢奶件(弁仿奶失件玄霜耨树  综岳  
 *
 *krynn 2001/12/9 加的注释
 *before == -1
 *before <> -1
 *krynn end
 *-----------------------------------------*/
void NPC_PKPetShop_BuyMain(int meindex,int talker,int before )
{
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char token[NPC_UTIL_GETARGSTR_BUFSIZE];
	int fd = getfdFromCharaIndex( talker);

	/*
	  曰  中白仿弘  蟆及犯□正银丹井白仿弘  饕及  蟆  丢永本□斥|  丹丢永本□斥  
	蜊醒蓟  丢永本□斥  伊矛伙箫曰卅中丢永本□斥  割  丢永本□斥  
	  蟆    尹月  尹卅中白仿弘  失奶  丞伊矛伙  袄蟾    飓  寞  域垫奶件白巧  
	  蟆    尹月  尹卅中白仿弘  失奶  丞伊矛伙  袄蟾    飓  寞  域垫奶件白巧  
	*/
	
	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
    if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("itemshop_GetArgStr_Err");
       	return;
    }

	/*--蟆荚及犯□正银丹井---*/
	if(before != -1) 
	{	/*--蟆荚及犯□正互酸匀化中月及匹职及树  反霜日卅仁    --*/
		sprintf(token,"0|0");

		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_ITEMSHOPMAIN, 
				WINDOW_BUTTONTYPE_NONE, 
				CHAR_WINDOWTYPE_WINDOWITEMSHOP_BUY_MSG,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);
	}else{

		char token2[NPC_UTIL_GETARGSTR_BUFSIZE];
		char buff2[256];
    	char buff[256];

		/*--备丢永本□斥毛潸  仄化弁仿奶失件玄卞霜月犯□正毛综月-*/
		/*--仇及支曰  反五凶卅中井手--*/
		NPC_Util_GetStrFromStrWithDelim( argstr, "main_msg", buff, sizeof( buff));
		NPC_Util_GetStrFromStrWithDelim( argstr, "buy_main", buff2, sizeof( buff2));
		sprintf(token,"0|1|%d|%s|%s|%s|", CHAR_WINDOWTYPE_WINDOWITEMSHOP_STARTMSG,
				CHAR_getChar( meindex, CHAR_NAME), buff, buff2);

		NPC_Util_GetStrFromStrWithDelim( argstr, "what_msg", buff, sizeof( buff));
		NPC_Util_GetStrFromStrWithDelim( argstr, "level_msg", buff2, sizeof( buff));
		snprintf( token2, sizeof( token2), "%s|%s", buff, buff2);

		/*--  侬  宁  --*/
		strncat( token, token2, sizeof( token));
			
		NPC_Util_GetStrFromStrWithDelim( argstr, "realy_msg", buff, sizeof( buff));
		NPC_Util_GetStrFromStrWithDelim( argstr, "itemfull_msg", buff2, sizeof( buff2));
		sprintf( token2, "|%s|%s", buff, buff2);

		/*--  侬    瑛--*/
		strncat(token , token2,sizeof(token));
		strcpy(token2, "|");
			
		/*--失奶  丞树  及      --*/
		NPC_PKPetShop_GetPetList( argstr, token2 );
		// krynn 2001/12/12 bebug 用
		print("%s",token2);
		// end krynn

		/*--丢永本□斥午失奶  丞树  及宁  --*/
		strncat( token, token2, sizeof( token));
	}

		/*--  侬  毛巨旦弗□皿今六月--*/
//		makeEscapeString( token, escapedname, sizeof(escapedname));

	/*--仇仇匹霜耨--*/
	lssproto_WN_send( fd, WINDOW_MESSAGETYPE_ITEMSHOPMAIN, 
				WINDOW_BUTTONTYPE_NONE, 
				CHAR_WINDOWTYPE_WINDOWITEMSHOP_BUY_MSG,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);

}

/*------------------------------------------------------
 *失奶  丞楮溢及  侬  毛综月(  丹  
 *------------------------------------------------------*/
void NPC_PKPetShop_GetPetList(char *argstr,char *argtoken)
{

	int i = 1;
	int tmp;
	int EnemyCnt;
	char *name ;
	char buff2[256];
	char buff[NPC_UTIL_GETARGSTR_LINEMAX];
	char token2[NPC_UTIL_GETARGSTR_BUFSIZE];
	double rate = 1.0;
	int loopcnt = 0;

	/*-伊□玄毛  月［  仃木壬ㄠ匹裔烂--*/
	if(NPC_Util_GetStrFromStrWithDelim( argstr, "buy_rate", buff2, sizeof( buff2))
	 != NULL){
		rate = atof( buff2);
	}
		
	/*-  健丹齿  毛潸    --*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "PetList", buff, sizeof( buff))
	 != NULL )
	{
	    while( getStringFromIndexWithDelim(buff,",",i,buff2,sizeof(buff2))
	     !=FALSE )
	    {
			i++;
	    	/*--涩烂白央奶伙及失奶  丞互 "-"匹嗉濠日木化中月井及民尼永弁--*/
			if(strstr( buff2, "-") == NULL) {
				/*--引内  蟆      --*/
				// krynn 2001/12/10
				EnemyCnt = ENEMY_getEnemyNum();
				for( tmp=0 ; tmp < EnemyCnt ; tmp++ )
				{
					if( ENEMY_getInt( tmp , ENEMY_ID ) == atoi( buff2 ) )
					{
						print("\nNPC_PKPetShop_GetPetList: tmp = %d", tmp);
						break;
					}
				}
				if( tmp == EnemyCnt )
				{
					return;
				}
				name = ENEMY_getChar( tmp , ENEMY_NAME );
				// krynn end
				/*--  蟆互        卅日｝失奶  丞互绣箕仄卅中及匹公及  寞反  骰--*/
				if(name == NULL) continue;

				loopcnt++;
				if(loopcnt == MAXSHOPPET) break;

				/*--  端及皿夫玄戊伙勾仁曰--*/
				NPC_PetStrStr( atoi( buff2), rate, name, token2, tmp);

				/*--丢永本□斥  侬  午  瑛--*/
	    		strncat( argtoken, token2, sizeof(token2));
			}
			else
			{
				return;
				/*krynn 2001/12/13 这段应该用不到了，先 mark，改为直接 return
				--失奶  丞互  15-25  及溥匹嗉濠日木化中月桦宁--
				int start;
				int end;

				//-"-"匹嗉濠日木凶铵户及醒袄午  及醒袄毛潸  --
				getStringFromIndexWithDelim( buff2, "-", 1, token2, sizeof(token2));
				start = atoi( token2);
				getStringFromIndexWithDelim( buff2, "-", 2 ,token2, sizeof(token2));
				end = atoi( token2);

				//--  寞互菅卞卅匀化中凶日｝  木赘尹月
				if(start > end)
				{
					tmp = start;
					start = end;
					end = tmp;
				}

				end++;

				//--"-"匹嗉濠日木凶坌及失奶  丞树  毛  月--
				for(; start < end ; start++ ) 
				{
					//--引内  蟆      --

				 	name = ITEM_getNameFromNumber( start );
					//--  蟆互        卅日｝失奶  丞互绣箕仄卅中及匹公及  寞反  骰--
					if(name == NULL) continue;

					loopcnt++;
					if(loopcnt == MAXSHOPPET) break;

					//--  端及皿夫玄戊伙勾仁曰--
					NPC_PetStrStr( start, rate, name, token2, tmp);

					//--丢永本□斥  侬  午  瑛--
		    		strncat( argtoken, token2, sizeof(token2));
				}*/
			}
		}
	}
}


/*-----------------------------------------------------------------
	皿夫玄戊伙综岳
-------------------------------------------------------------------*/
void NPC_PetStrStr(int petID,double rate,char *name,char *token2,int index)
{
	int i;
	int gold;
	int level;
	int graNo;
	int TempNo;
	int EnemyTempNum;
	char info[1024];
	//char tryItem[256];	// krynn 2001/12/12 只是要看 getItemInfoFromNumber 读出来的字串长什麽样的
	char escape[256] = {"PK Server 宠"};	

	//krynn 2001/12/10 try
	//gold  = ITEM_getcostFromITEMtabl( itemID);
	//level = ITEM_getlevelFromITEMtabl( itemID);
	//graNo = ITEM_getgraNoFromITEMtabl( itemID);
	TempNo = ENEMY_getInt( index , ENEMY_TEMPNO );
	EnemyTempNum = ENEMYTEMP_getEnemyNum();
	for( i=0 ; i < EnemyTempNum ; i++ )
	{
		if( ENEMYTEMP_getInt( i , E_T_TEMPNO ) == TempNo )
		{
			break;
		}
	}
	if( i == EnemyTempNum )
	{
		return;
	}
	gold  = RAND(0,20);
	level = 0;
	graNo = ENEMYTEMP_getInt( i , E_T_IMGNUMBER );
	//print("\nPKPetShop::NPC_PetStrStr(): TempNo = %d ; graNo = %d",TempNo,graNo);
	/*--伊□玄毛井仃月--*/
	gold=(int)(gold * rate);

	//strcpy( tryItem,ITEM_getItemInfoFromNumber( 10 ) );
	//print("PKPetShop::NPC_PetStrStr(): try = %s\n",tryItem);
	//krynn end

	makeEscapeString( escape, info, sizeof( info));

	makeEscapeString( name, escape, sizeof( escape));

	sprintf( token2, "%s|0|%d|%d|%d|%s|", escape, level, gold, graNo, info);
}


/*-------------------------------------------
 *(  丹)
 *弁仿奶失件玄井日忒匀凶  凶瑛绊毛  掏今六月
 *
 *------------------------------------------*/
BOOL NPC_PKPetShop_SetNewPet(int meindex,int talker,char *data)
{

	char buf[1024];
	char buff2[128];
	int i = 1, j = 1;
	int select;
	int kosuu = 0;
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	double rate = 1.0;
	int gold = 0;		
	int EmptyPetCnt=0;

	/*--忒匀化五凶犯□正毛本伊弁玄午蜊醒卞坌荸--*/
	print("\nNPC_PKPetShop_SetNewPet: data = %s",data);
	getStringFromIndexWithDelim( data, "|", 1, buf, sizeof( buf));
	select=atoi(buf);		// krynn 2001/12/10  select 是玩家传回要买的第几样
	print("\nNPC_PKPetShop_SetNewPet: select = %d",select);
	if(select == 0) return FALSE;
	getStringFromIndexWithDelim( data, "|", 2, buf, sizeof( buf));
	kosuu=atoi(buf);
	print("\nNPC_PKPetShop_SetNewPet: kosuu(玩家要买的数量) = %d",kosuu);

	if( kosuu <= 0 ) return FALSE;
    
	/* 仍潜谛  及矢永玄及坞五毛茧允 */
    if( !CHAR_CHECKINDEX(talker) )
	{
		return FALSE;
	}
	for( i=0 ; i < CHAR_MAXPETHAVE ; i++ ) 
	{
	    if( CHAR_getCharPet( talker,i) == -1 )
		{
			EmptyPetCnt++;
		}
    }
	// 有 EmptyPetCnt 个宠物空位
    /* 坞五互  中 */
 	print("\nNPC_PKPetShop_SetNewPet:EmptyPetCnt(玩家有的空位) = %d",EmptyPetCnt);
	if( EmptyPetCnt <= 0 ) return FALSE;
	if( EmptyPetCnt > CHAR_MAXPETHAVE )
	{
		EmptyPetCnt = CHAR_MAXPETHAVE;
	}
	if( kosuu > EmptyPetCnt )
	{
		kosuu = EmptyPetCnt;
	}

	// krynn 2001/12/10
	// 应该用不到，所以 mark 起来
	/*--蜊醒及民尼永弁  癫卞蝈    月井＂
	for( i = CHAR_STARTITEMARRAY ; i < CHAR_MAXITEMHAVE ; i++ ) {
		itemindex = CHAR_getItemIndex( talker , i );

		if( !ITEM_CHECKINDEX( itemindex) ) {
			kosuucnt++;
		 }
	}

	--忒匀化  凶蜊醒及  互  端及蜊醒  扔□田础  方曰聂中午云井仄中及匹
	--扔□田□础及  毛  木月
	if( kosuucnt < kosuu){
		kosuu = kosuucnt;
	}
	--未夫及桦宁反巨仿□
	if(kosuucnt == 0 ){
		return FALSE;
	}
	krynn end */

	i = 1;

	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
	if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("shop_GetArgStr_Err");
       	return FALSE;
	}

	/*---伊□玄毛潸    卅仃木壬1.0)-*/
	if(NPC_Util_GetStrFromStrWithDelim( argstr, "buy_rate", buf, sizeof( buf))
	 != NULL) {
		rate= atof( buf);
	}
	
	/*--失奶  丞及馨笛毛垫丹午仇欠-*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "PetList", 
		buf, sizeof( buf)) != NULL )
	{
		while(getStringFromIndexWithDelim(buf , "," , j, buff2, sizeof(buff2))
		 != FALSE )
		{
			j++;
			/*--  "-"互殖引木化中月井升丹井--*/
			if(strstr( buff2, "-") == NULL)
			{	// krynn 2001/12/10 try
				//if( ITEM_getcostFromITEMtabl(atoi(buff2)) !=-1) {
					// 
					if ( i == select)
					{
						/*---失奶  丞及综岳---*/
						/*--蜊醒坌综岳--*/
						if(NPC_AddPetBuy(meindex, talker,atoi(buff2),kosuu,rate) != TRUE)
						{
							return FALSE;
						}
						return TRUE;
					}
					i++;		
				// krynn end}
			}else{
				/*--失奶  丞互  15-25  及溥匹霜日木凶桦宁--*/
				int start;
				int end;

				/* "-"匹嗉濠日木凶铵户及醒袄午  及醒袄毛潸  --*/
				getStringFromIndexWithDelim( buff2, "-", 1, argstr, sizeof(argstr));
				start = atoi( argstr);
				getStringFromIndexWithDelim( buff2, "-", 2 ,argstr, sizeof(argstr));
				end = atoi( argstr);
				end++;

				/*--  寞互菅卞卅匀化中凶日｝  木赘尹月**/
				if(start > end){
					gold = start;
					start = end;
					end = gold;
				}

				/*--"-"匹嗉濠日木凶坌及失奶  丞毛树  毛  月--*/
				for(; start < end ; start++ ) {
					if( ITEM_getcostFromITEMtabl( start) != -1) {
						if ( i == select) {
							/*---失奶  丞及综岳---*/
							/*--蜊醒坌综岳--*/
							if(NPC_AddPetBuy(meindex, talker, start, kosuu, rate) != TRUE)
							{
								return FALSE;
							}
							return TRUE;
						}
						i++;
					}
				}
			}
		}
	}

	return FALSE;

}


/*---------------------------------------------
 *失奶  丞及馨笛毛垫丹
 *--------------------------------------------*/
BOOL NPC_AddPetBuy(int meindex, int talker,int petID,int kosuu,double rate)
{
	int i,j,k,index,EnemyCnt,UpLevel;
	int gold;
	int ret;
	int maxgold;
	int Grade=0;
	char buf[1024];
	char msgbuf[64];
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	
	// krynn 2001/12/15 get get's grade of this PKPetShop
	if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("shop_GetArgStr_Err");
       	return FALSE;
	}
	if(NPC_Util_GetStrFromStrWithDelim( argstr, "Grade", buf, sizeof( buf))
	 != NULL) 
	{
		Grade = atoi( buf );
	}
	// end krynn

	/*--伊□玄毛井仃月--*/
	// krynn 2001/12/11 mark and change
	//gold = ITEM_getcostFromITEMtabl( itemID);
	gold = 4;
	// krynn end
	gold = (int)(gold * rate);
	maxgold = gold * kosuu;

	if(CHAR_getInt( talker, CHAR_GOLD) < maxgold ) return FALSE;

	/*--云嗯毛蛹日允--*/
	CHAR_setInt( talker, CHAR_GOLD,CHAR_getInt( talker, CHAR_GOLD) - maxgold);

	EnemyCnt = ENEMY_getEnemyNum();
	for( index=0 ; index < EnemyCnt ; index++ )
	{
		if( ENEMY_getInt( index , ENEMY_ID ) == petID )
		{
			print("\nNPC_AddPetBuy: index = %d", index);
			break;
		}
	}
	if( index == EnemyCnt )
	{
		return FALSE;
	}

	/*--蜊醒坌综岳--*/
	for(i = 0 ; i < kosuu ; i++)
	{
		if( (ret = ENEMY_createPetFromEnemyIndex( talker , index )) == -1 )
		{
			return FALSE;
		};
		/******************/
		/* 矢永玄树  霜月 */
		/******************/
		// 升仇卞反中匀凶井卅
		for( j = 0 ; j < CHAR_MAXPETHAVE ; j++ )
		{
			if( CHAR_getCharPet( talker , j ) == ret )
			{
				break;
			}
		}
		if( j == CHAR_MAXPETHAVE ){
			return FALSE;
		}
		if( CHAR_CHECKINDEX( ret ) == TRUE ){
			CHAR_setMaxExpFromLevel( ret, Grade);
			UpLevel = CHAR_LevelUpCheck( ret , talker);
			for( k = 0; k < UpLevel; k ++ ){
				CHAR_PetLevelUp( ret );
				CHAR_PetAddVariableAi( ret, AI_FIX_PETLEVELUP );
			}
			CHAR_complianceParameter( ret );
			CHAR_setInt( ret , CHAR_HP , CHAR_getWorkInt( ret , CHAR_WORKMAXHP ) );

			snprintf( msgbuf, sizeof( msgbuf ), "K%d", j );
			CHAR_sendStatusString( talker, msgbuf );
			
			snprintf( msgbuf, sizeof( msgbuf ), "W%d", j );
			CHAR_sendStatusString( talker, msgbuf );
		}
	}
	CHAR_send_P_StatusString( talker, CHAR_P_STRING_GOLD);
	return TRUE;
}



/*----------------------------------------
 *丢瓦亘□    
 *----------------------------------------*/
void NPC_PKPetShop_Menu(int meindex,int talker)
{
	char	argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char	token[NPC_UTIL_GETARGSTR_LINEMAX];
	char	buff[256];
	int		fd = getfdFromCharaIndex( talker);

	/* 饕及  蟆  丢永本□斥| */
	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
    if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
		print("shop_GetArgStr_Err");
       	return;
    }
    	
    NPC_Util_GetStrFromStrWithDelim( argstr, "main_msg", buff, sizeof( buff));
	snprintf(token, sizeof(token),"%s|%s",CHAR_getChar( meindex, CHAR_NAME), buff);

	//	print("%s",escapedname);
	/*--仇仇匹霜耨--*/
	//krynn 2001/12/10	这里的参数似乎可以延用 ItemShop 的 code，先用用看
	lssproto_WN_send( fd, WINDOW_MESSAGETYPE_ITEMSHOPMENU, 
				WINDOW_BUTTONTYPE_NONE, 
				CHAR_WINDOWTYPE_WINDOWITEMSHOP_STARTMSG,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);
	//krynn end
}


/*-------------------------------------------
 *	  月质  (皿夫玄戊伙毛综岳  
 *	
 *-------------------------------------------*/
void NPC_PKPetShop_SellMain(int meindex,int talker,int before)
{

	char	argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char	token[NPC_UTIL_GETARGSTR_BUFSIZE];
	int fd = getfdFromCharaIndex( talker);


	/*
	  曰  中白仿弘  蟆及犯□正银丹井白仿弘  饕及  蟆  丢永本□斥|  月丢永本□斥  
	云嗯互中匀天中卞卅月方丢永本□斥  割  丢永本□斥  
	  蟆    木月  木卅中白仿弘  袄蟾    飓  寞  域垫奶件白巧  失奶  丞    寞  ㄠ井日  
	  蟆    木月  木卅中白仿弘  袄蟾    飓  寞  域垫奶件白巧  失奶  丞    寞  ㄠ井日  
	*/
	
	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
    if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("shop_GetArgStr_Err");
       	return;
    }

	/*--蟆荚及犯□正银丹井---*/
	if(before != -1) {

		/*--蟆荚及犯□正互酸匀化中月及匹职及树  反霜日卅仁    --*/
		sprintf(token,"1|0");
		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_ITEMSHOPMAIN
							+CHAR_getWorkInt(meindex,NPC_PKPETSHOP_WORK_NO), 
					WINDOW_BUTTONTYPE_NONE, 
					CHAR_WINDOWTYPE_WINDOWITEMSHOP_SELL_MSG,
					CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
					token);
	
	}else{

		char token2[NPC_UTIL_GETARGSTR_BUFSIZE];
		char buff2[256];
	   	char buff[256];

		/*--备丢永本□斥毛潸  仄化弁仿奶失件玄卞霜月犯□正毛综月-*/
		/*--仇及支曰  反五凶卅中井手--*/
		NPC_Util_GetStrFromStrWithDelim( argstr, "main_msg", buff, sizeof( buff));
		NPC_Util_GetStrFromStrWithDelim( argstr, "sell_main", buff2, sizeof( buff));
		sprintf( token, "1|1|%d|%s|%s|%s|", CHAR_WINDOWTYPE_WINDOWITEMSHOP_STARTMSG,
				CHAR_getChar( meindex, CHAR_NAME), buff, buff2);

		NPC_Util_GetStrFromStrWithDelim( argstr, "stone_msg", buff, sizeof( buff));

		if(CHAR_getWorkInt(meindex,NPC_PKPETSHOP_WORK_EXPRESS) == 1 ) {
			NPC_Util_GetStrFromStrWithDelim( argstr, "exrealy_msg", buff2, sizeof(buff2));
		}else{
			NPC_Util_GetStrFromStrWithDelim( argstr, "realy_msg", buff2, sizeof( buff2));
		}
		sprintf( token2,"%s|%s|", buff, buff2);

		/*--失奶  丞树  及      --*/
		NPC_PKPetShop_GetLimtPetList( talker,argstr, token2, -1);

		/*--丢永本□斥午失奶  丞树  及宁  --*/
		strncat( token, token2, sizeof( token));
	
		/*--仇仇匹霜耨--*/
		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_ITEMSHOPMAIN+
					CHAR_getWorkInt(meindex,NPC_PKPETSHOP_WORK_NO), 
					WINDOW_BUTTONTYPE_NONE, 
					CHAR_WINDOWTYPE_WINDOWITEMSHOP_SELL_MSG,
					CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
					token);
	}
}





/*--------------------------------

愤坌互云饕卞  月失奶  丞及  侬  毛及赏  

 *-------------------------------*/
int NPC_PKPetShop_GetLimtPetList(int talker, char *argstr, char* token2,int sell)
{

	char token[NPC_UTIL_GETARGSTR_LINEMAX];
	char buff[NPC_UTIL_GETARGSTR_LINEMAX];
	char token3[NPC_UTIL_GETARGSTR_LINEMAX];
	int k = 0 , i = 1 , j = 0;
	int imax;
	int itemtype = 0;
	int itemindex;
	int okflg = 0;
	char buf[256];
	int flg=0;
	int cost;
	
	
	if(sell == -1 ){
		i = CHAR_STARTITEMARRAY;
		imax = CHAR_MAXITEMHAVE;
		flg = -1;
	}else{
		i= sell;
		imax= sell + 1;
		flg = 1;
	}	
	
	/*---  木月失奶  丞毛潸  允月［--*/
	/**  旦矢扑乓伙失奶  丞毛手匀化中凶日  伊□玄匹煌遥--*/
	/*-- 旦矢扑乓伙质  匹皿夫弘仿丞互    --*/

	for( ; i < imax ; i++ ){
		okflg=0;
		itemindex = CHAR_getItemIndex( talker , i );
		
		if( ITEM_CHECKINDEX( itemindex) ){

			/*--失奶  丞及正奶皿互域谯仄凶日｝  木月--*/
			if( NPC_Util_GetStrFromStrWithDelim( argstr,"LimitItemType",
			buff, sizeof( buff))
			 != NULL )
			{
				k = 1;
				while(getStringFromIndexWithDelim(buff , "," , k, token, sizeof(token))
				 != FALSE )
				{
#ifdef _ITEM_TYPETABLE
					int cmpmaxitem = sizeof(TypeTable)/sizeof(TypeTable[0]);
#endif
					k++;
#ifdef _ITEM_TYPETABLE
					for(j = 0 ; j < cmpmaxitem ; j++){
#else
					for(j = 0 ; j < ITEM_CATEGORYNUM+3 ; j++){
#endif
						if(strcmp( TypeTable[ j].arg  , token) == 0 ) {
							itemtype = TypeTable[ j].type;
							if(ITEM_getInt(itemindex,ITEM_TYPE) == itemtype) {

								/*--  侬  综岳--*/
								cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
								if(cost != -1) return cost;
								strncat( token2, token3, sizeof( token3));
								okflg = 1;
							}else if(itemtype == 30){
								if( 8 <= ITEM_getInt(itemindex,ITEM_TYPE) 
									&& (ITEM_getInt(itemindex,ITEM_TYPE) <= 15) ){
									/*--  侬  综岳--*/
									cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
									if(cost != -1) return cost;
									strncat(token2,token3,sizeof(token3));
									okflg = 1;
								}
							}else if(itemtype == 40){
								if(( 0 <= ITEM_getInt(itemindex,ITEM_TYPE) 
								  && (ITEM_getInt(itemindex,ITEM_TYPE) <= 4)) 
								 || (17 <= ITEM_getInt(itemindex,ITEM_TYPE) 
								  && (ITEM_getInt(itemindex,ITEM_TYPE) <= 19))
								) {
									/*--  侬  综岳--*/
									cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
									if(cost != -1) return cost;
									strncat(token2,token3,sizeof(token3));
									okflg = 1;
								}
							}else if(itemtype == 50){
								if( 5 <= ITEM_getInt(itemindex,ITEM_TYPE) 
								&& (ITEM_getInt(itemindex,ITEM_TYPE) <= 7) ){
									/*--  侬  综岳--*/
									cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
									if(cost != -1) return cost;
									strncat(token2,token3,sizeof(token3));
									okflg = 1;
								}
							}
							break;
						}
					}
						
					if(okflg == 1) break;
				}
			}
			/*--正奶皿卞卅仁化  涛  寞仄化  木月失奶  丞井民尼永弁--*/
			if( (NPC_Util_GetStrFromStrWithDelim( argstr, "LimitItemNo",
			buff,sizeof( buff))
			 != NULL)
				&& okflg == 0 )
			{
				k = 1;
				while(getStringFromIndexWithDelim(buff , "," , k, token, sizeof(token))
				 != FALSE )
				{
					k++;
					/*--窒手涩烂今木化卅井匀凶日｝  骰允月-*/
					if(strstr( token, "-")==NULL && strcmp(token,"") != 0) {
						if(ITEM_getInt(itemindex,ITEM_ID) == atoi(token)) {
							/*--  侬  综岳--*/
							cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
							if(cost != -1) return cost;
							strncat(token2,token3,sizeof(token3));
							okflg=1;
						}
					}else if (strstr( token, "-") != NULL){
						int start;
						int end;
						int work;

						/*--  侬  综岳--*/
						/* "-"匹嗉濠日木凶铵户及醒袄午  及醒袄毛潸  --*/
						getStringFromIndexWithDelim( token, "-", 1, buf, sizeof(buf));
						start = atoi( buf);
						getStringFromIndexWithDelim( token, "-", 2 ,buf, sizeof(buf));
						end = atoi( buf);

						/*--  寞互菅卞卅匀化中凶日｝  木赘尹月**/
						if(start > end){
							work = start;
							start = end;
							end = work;
						}

						end++;
						/*--"-"匹嗉濠日木凶坌及失奶  丞毛树  毛  月--*/
						if( (start <= ITEM_getInt(itemindex,ITEM_ID))
						 && (ITEM_getInt(itemindex,ITEM_ID) < end) )
						 {
							/*--  侬  综岳--*/
							cost = NPC_GetSellPetList(itemindex,0,argstr,token3,i,sell);
							if(cost != -1) return cost;
							strncat(token2,token3,sizeof(token3));
							okflg = 1;
						}
					}
				}
			}

			/*--  月仇午互匹五卅中--*/
			if(okflg == 0) {
				cost = NPC_GetSellPetList(itemindex, 1, argstr, token3, i, sell);
				if(sell != -1) return -1;
				strncat( token2, token3, sizeof( token3));
			}
			
		}
	}
	return -1;
}



/*----------------------------------------------------------

	弁仿奶失件玄卞霜耨允月皿夫玄戊伙及综岳

 *----------------------------------------------------------*/
int NPC_GetSellPetList(int itemindex,int flg, char *argstr,char *argtoken,int select,int sell)
{

	char buff[256];
	double rate = 0.2;
	char buff2[256];
	char buff3[64];
	int k = 1;
	int cost = -1;

	/*--旦矢扑乓伙伊□玄--**/
	if(NPC_Util_GetStrFromStrWithDelim( argstr,"special_item",buff, sizeof( buff))
	!= NULL)
	{
		if(NPC_Util_GetStrFromStrWithDelim( argstr,"special_rate",buff2, sizeof( buff2))
		 != NULL )
		{
			rate = atof(buff2);
		}else{
			rate = 1.2;
		}
		
		while(getStringFromIndexWithDelim(buff , "," , k, buff2, sizeof(buff2)) !=FALSE )
		{
			k++;

			if(strstr( buff2, "-") == NULL && strcmp(buff2,"") != 0) {
				if(ITEM_getInt(itemindex,ITEM_ID) == atoi(buff2)){
					cost = NPC_SellPetstrsStr( itemindex,0, rate, argtoken,select,sell);
					return cost;
				}
			}else if (strstr( buff2, "-") != NULL){
				int start;
				int end;
				int work;

				/*--  侬  综岳--*/
				/* "-"匹嗉濠日木凶铵户及醒袄午  及醒袄毛潸  --*/
				getStringFromIndexWithDelim( buff2, "-", 1, buff3, sizeof(buff3));
				start = atoi( buff3);
				getStringFromIndexWithDelim( buff2, "-", 2 ,buff3, sizeof(buff3));
				end = atoi( buff3);

				/*--  寞互菅卞卅匀化中凶日｝  木赘尹月**/
				if(start > end){
					work = start;
					start = end;
					end = work;
				}
				end++;
	
				/*--"-"匹嗉濠日木凶坌及失奶  丞毛树  毛  月--*/
				if( (start <= ITEM_getInt(itemindex,ITEM_ID))
					&&  (ITEM_getInt(itemindex,ITEM_ID) < end)
				){
			
					cost = NPC_SellPetstrsStr( itemindex,0, rate, argtoken,select,sell);
					return cost;
				}
			}
		}
	}

	/*--用□穴伙伊□玄--*/
	if( NPC_Util_GetStrFromStrWithDelim( argstr,"sell_rate",buff, sizeof( buff))
	 != NULL )
	{
		rate = atof(buff);
		cost = NPC_SellPetstrsStr( itemindex, flg ,rate, argtoken,select,sell);
		return cost;
	}

	return cost;
}


/*------------------------------------------
 
   侬  毛综月(丹曰迕)
 
*------------------------------------------*/
int NPC_SellPetstrsStr(int itemindex,int flg,double rate,char *argtoken,int select,int sell)
{
	int cost;
	char escapedname[256];
	char name[256];	
	char *eff;
	

	cost = ITEM_getInt( itemindex, ITEM_COST);
	cost = (int)(cost * rate);

	if(sell != -1) return cost;

		
	//strcpy( escapedname, ITEM_getChar( itemindex, ITEM_NAME));
	strcpy( escapedname, ITEM_getChar( itemindex, ITEM_SECRETNAME));
	makeEscapeString( escapedname, name, sizeof( name));
	eff=ITEM_getChar(itemindex, ITEM_EFFECTSTRING);
	makeEscapeString( eff, escapedname, sizeof(escapedname));



	sprintf(argtoken,"%s|%d|%d|%d|%s|%d|",
			name,
			flg,
			cost,
			ITEM_getInt( itemindex, ITEM_BASEIMAGENUMBER),
			escapedname,
			select
	);

	return -1;

}

/*--------------------------------------------
 *
 *弁仿奶失件玄井日瑛绊互忒匀化五凶午五    月    
 *
 *-------------------------------------------*/
BOOL NPC_PKPetShop_SellNewPet(int meindex,int talker,char *data)
{
	int select;
	int cost;
	int oldcost;
	char token[32];
	int k;
	int itemindex;
	char	argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char token2[256];
	
	if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
		print("GetArgStrErr");
		return FALSE;
	}


	/*--忒匀化  凶犯□正及坌荸--*/
	getStringFromIndexWithDelim(data , "|" ,1, token, sizeof( token));
	select = atoi(token);
	getStringFromIndexWithDelim(data , "|" ,2, token, sizeof( token));
	oldcost = atoi(token);

	if(select == 0) return FALSE;

	cost = NPC_PKPetShop_GetLimtPetList( talker,argstr, token2,select);


	/*--啜丹手及毛丹欠丹午仄凶午五及巨仿□--*/
	if(oldcost != cost || cost == -1)
	{
		int fd = getfdFromCharaIndex( talker);
		char token[256];
		
		sprintf(token,"\n\n哎呀!对不起"
					"\n\n对不起啊 ! 可不可以再选一次呢？"
		);
		
		k = select;
		itemindex = CHAR_getItemIndex( talker ,k);
		
		
		/*--夫弘及请  --*/
		if(itemindex != -1) {
			print("\n%s(%d,%d,%d):和选择的东西不同error([%s(%d)]要消失了）",
					CHAR_getChar(talker, CHAR_NAME),
					CHAR_getInt( talker, CHAR_FLOOR),
					CHAR_getInt( talker, CHAR_X ),
					CHAR_getInt( talker, CHAR_Y ),
					ITEM_getChar(itemindex, CHAR_NAME),
					ITEM_getInt( itemindex, ITEM_ID )
			);
			LogItem(
					CHAR_getChar( talker, CHAR_NAME ), /* 平乓仿   */
					CHAR_getChar( talker, CHAR_CDKEY ),
#ifdef _add_item_log_name  // WON ADD 在item的log中增加item名称
					itemindex,
#else
	       			ITEM_getInt( itemindex, ITEM_ID ),  /* 失奶  丞  寞 */
#endif
					"SellErr",
					CHAR_getInt( talker, CHAR_FLOOR),
					CHAR_getInt( talker, CHAR_X ),
					CHAR_getInt( talker, CHAR_Y ),
					ITEM_getChar( itemindex, ITEM_UNIQUECODE),
						ITEM_getChar( itemindex, ITEM_NAME),
						ITEM_getInt( itemindex, ITEM_ID)
			);
		}else{
			print("\n%s(%d,%d,%d):和选择的东西不同error(没有任何item存在）",
					CHAR_getChar(talker, CHAR_NAME),
					CHAR_getInt( talker, CHAR_FLOOR),
					CHAR_getInt( talker, CHAR_X ),
					CHAR_getInt( talker, CHAR_Y )
			);
			LogItem(
					CHAR_getChar( talker, CHAR_NAME ), /* 平乓仿   */
					CHAR_getChar( talker, CHAR_CDKEY ),
	       			-1,  /* 失奶  丞  寞 */
					"SellErr",
					CHAR_getInt( talker, CHAR_FLOOR),
					CHAR_getInt( talker, CHAR_X ),
					CHAR_getInt( talker, CHAR_Y ),
					"-1", "NULL", -1 );
		}
		/*--仇仇匹霜耨--*/
		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_MESSAGE, 
				WINDOW_BUTTONTYPE_OK, 
				CHAR_WINDOWTYPE_WINDOWITEMSHOP_LIMIT,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);

		
		return FALSE;
	}

	k = select;
	itemindex=CHAR_getItemIndex( talker ,k);

	if(itemindex != -1) {
		{
			LogItem(
				CHAR_getChar( talker, CHAR_NAME ), /* 平乓仿   */
				CHAR_getChar( talker, CHAR_CDKEY ),
#ifdef _add_item_log_name  // WON ADD 在item的log中增加item名称
				itemindex,
#else
	       		ITEM_getInt( itemindex, ITEM_ID ),  /* 失奶  丞  寞 */
#endif
				"Sell",
				CHAR_getInt( talker,CHAR_FLOOR),
				CHAR_getInt( talker,CHAR_X ),
				CHAR_getInt( talker,CHAR_Y ),
				ITEM_getChar( itemindex, ITEM_UNIQUECODE),
				ITEM_getChar( itemindex, ITEM_NAME),
				ITEM_getInt( itemindex, ITEM_ID)

			);
		}
		
	}

	CHAR_DelItem( talker, k);
	CHAR_AddGold( talker, cost);
	CHAR_send_P_StatusString( talker, CHAR_P_STRING_GOLD);

	return TRUE;
}



void NPC_LimitPetShop(int meindex,int talker,int select)
{

	int fd = getfdFromCharaIndex( talker);
	char token[NPC_UTIL_GETARGSTR_LINEMAX];
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char buf[1024];

	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
	if( NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("shop_GetArgStr_Err");
       	return;
	}

	/*--  中潸曰毁  饕匹允丢永本□斥-*/
	if(NPC_Util_GetStrFromStrWithDelim( argstr, "sellonly_msg", buf, sizeof( buf))
	!=NULL)
	{
		sprintf(token,"\n\n%s", buf);

		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_MESSAGE, 
				WINDOW_BUTTONTYPE_YESNO, 
				CHAR_WINDOWTYPE_WINDOWITEMSHOP_LIMIT,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);

	}else{
		CHAR_talkToCli( talker, meindex, "这是买卖专门店。",CHAR_COLORWHITE);
	}
	return;
}


/*--扪霜盒今氏--*/
void NPC_PKPetShop_ExpressmanCheck(int meindex,int talker)
{
	int fd = getfdFromCharaIndex( talker);
	char token[1024];
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char buf[1024];

	/*--云饕及白央奶伙  中坭反白央奶伙互钒仃卅井匀凶午五反蔽  --*/
	if( NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr)) == NULL) {
       	print("shop_GetArgStr_Err");
       	return;
	}


	/*--  中潸曰毁  饕匹允丢永本□斥-*/
	NPC_Util_GetStrFromStrWithDelim( argstr, "main_msg", buf, sizeof( buf));
	sprintf(token,"4\n              %s\n\n%s"
					"\n\n          ＜  打工  ＞      "
				  "\n\n          ＜交付行李＞"
					,CHAR_getChar(meindex,CHAR_NAME),buf);

	lssproto_WN_send( fd, WINDOW_MESSAGETYPE_SELECT, 
			WINDOW_BUTTONTYPE_CANCEL, 
			CHAR_WINDOWTYPE_WINDOWITEMSHOP_EXPRESS,
			CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
			token);

	return;


}


#endif
 // _PKPETSHOP




