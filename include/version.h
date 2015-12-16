#ifndef __VERSION_H__
#define __VERSION_H__
#include "correct_bug.h"  //BUG FIX
#include "version_pk.h"   //PK SERVER

/*Server 鐗堟湰鎺у埗*/
#define _NEW_SERVER_
#define _SERVER_NUMS

//#define _DEBUG_JZ								//鍚変粩 ADD 鍙敤浜庤皟璇?鍏朵粬鎯呭喌璇峰叧闂?
#ifdef _DEBUG_JZ
#define SERVER_VERSION "SMO v2.5.尾8.16 For Linux For Linux Debug Marking"
#else
#define SERVER_VERSION "SMO v2.5.尾8.16 For Linux"
#endif

#define UNIQUE_KEYCODEITEM	100
#define UNIQUE_KEYCODEPET	"i"

#define _SA_VERSION_70				// (鍙紑鏀? WON ADD 鐭冲櫒鏃朵唬7.0 鐨勭増鏈帶鍒?
//#define _DEFAULT_PKEY "Wonwonwon"	// (鍙紑鏀?( 鐭冲櫒 6.0 )
//#define _RUNNING_KEY  "11111111"	// (鍙紑鏀?( 鐭冲櫒 6.0 )
#define _DEFAULT_PKEY "12345678"	// (鍙紑鏀?( 鐭冲櫒 6.0 )
#define _RUNNING_KEY  "12345678"	// (鍙紑鏀?( 鐭冲櫒 6.0 )

#define _VERSION_20010911	        // (鍙紑鏀? 9.11 缂栫爜淇敼

// -------------------------------------------------------------------
//鏂板姛鑳斤細娴嬭瘯浼烘湇鍣ㄤ笓鐢?浜哄憳锛氬溅璞?
#define _TEST_PETCREATE             // (涓嶅彲寮€) ANDY 娴嬪疇鐨凣M鎸囦护
//#define _LOGIN_ADDITEM			// (涓嶅彲寮€) ANDY 鐧诲叆鍔犳弧鐗╁搧
//#define _NEW_TESTSERVER			// (涓嶅彲寮€) ANDY 鐜╁鍒涙柊浜虹墿鏃讹紝缁欎簣浜旇浆125绛夌骇鍙婂弫鍙疇鐗?
//#define _TEST_PETFUSIONTIME		// (涓嶅彲寮€) ANDY 娴嬭瘯瀹犵墿铻嶅悎  椋熸椂闂村姞蹇?
/* -------------------------------------------------------------------
 * 涓撴锛氬鏃忓簞鍥暟閲忎慨鏀?浜哄憳锛氬皬鐟溿€佸溅鍕嬨€佸織浼熴€佸皬姘?
 */

/*
淇敼瑁呭洯鏁伴噺鏂瑰紡锛?
Account Server 绋嬪紡:
	acfamily.h	MAX_FMPOINT瑕佷慨鏀?
Account Server 娓告垙鐜:
	saac/family/fmpoint/db_fmpoint妗ｆ涓』鏂板搴勫洯鍏ュ彛鍧愭爣绛夎瀹?
	搴勫洯杩涘叆鍥惧眰|搴勫洯杩涘叆锛稿骇鏍噟搴勫洯杩涘叆锛瑰骇鏍噟搴勫洯鏃忛暱鍥惧眰|搴勫洯閭昏繎涔嬫潙搴剕鍗犻搴勫洯涔嬪鏃?index|鍗犻搴勫洯涔嬪鏃?name|鍗犻搴勫洯涔嬪鏃忕患鍚堝０鏈涘€?
	渚嬪锛?
		100|607|563|1041|1|3|shan|3132238
		200|73|588|2031|2|||
Game Server 绋嬪紡锛?
	version.h FAMILY_MAXHOME銆丮ANORNUM瑕佷慨姝?
	family.c	 FM_PKFLOOR	椤诲璁炬垬鏂楀浘灞?
				 FAMILY_RidePet() 涓』鍔犲叆鏃忛暱瀹跺浘灞?
				 FAMILY_LeaderFunc() 涓』鍔犲叆閭€璇峰嚱id
	npcutil.c addNpcFamilyTax function涓』鍔犲叆(搴勫洯鍥惧眰%100)姝や负搴勫洯绋庢敹閮ㄤ唤
Game Server 娓告垙鐜:
	gmsv_v2/data/npc/family/manorsman.arg* id椤讳慨姝?
	gmsv_v2/data/npc/family/scheduleman.arg* id椤讳慨姝?
*/

#define _FAMILY_MANORNUM_CHANGE	// CoolFish 鐢ㄦ潵淇敼瑁呭洯鏁伴噺(4.0)
#ifdef _FAMILY_MANORNUM_CHANGE
#define _FIX_10_FMPOINT			//锛堝彲寮€鏀撅級鍚変粩ADD 鍐板簞
#ifdef _FIX_10_FMPOINT
#define FAMILY_MAXHOME			4	// (4.0) 瀹舵棌鎹偣
#define MANORNUM                4	// (4.0) 搴勫洯鏁伴噺
#define FMPOINTNUM				4   // (4.0) 鏈夋嵁鐐瑰鏃忕殑鏈€澶ф暟閲?
#else
#define FAMILY_MAXHOME			9	// (4.0) 瀹舵棌鎹偣
#define MANORNUM                9	// (4.0) 搴勫洯鏁伴噺
#define FMPOINTNUM				9   // (4.0) 鏈夋嵁鐐瑰鏃忕殑鏈€澶ф暟閲?
#endif
#endif
#define _FMVER21		        // (鍙紑鏀? 瀹舵棌鑱屾帉鍔熻兘
#define _PERSONAL_FAME	    	// (鍙紑鏀? Arminius 8.30 瀹舵棌涓汉澹版湜
// -------------------------------------------------------------------
//涓撴锛氱煶鍣ㄦ椿鍔ㄨ嚜鍔ㄥ寲		浜哄憳锛氭檽濞併€佸楹?
//鍚変粩淇敼 鍘绘帀鐭冲櫒鏈嶅姟鍛楴PC绛夊姛鑳?
//#define _SERVICE     	    	// (鍙紑鏀? Terry 2001/10/03 娲诲姩鍔熻兘鑷姩鍖?

#define _EVERYONE_RIDE	    	// (鍙紑鏀? Robin 0924 楠戝疇骞虫皯鍖?
// -------------------------------------------------------------------
//涓撴锛氭敾鍑绘€у拻鏈殑鍒朵綔	浜哄憳锛氱瑑蹇?
// #define __ATTACK_MAGIC_MSG   // (涓嶅紑鏀?
#define __ATTACK_MAGIC          // (鍙紑鏀?	鎻愪緵鎴樺満涓殑鏀诲嚮鎬у拻鏈?
#define _ADD_ACTION             // (鍙紑鏀? 涓€鑸琋PC鍔ㄤ綔鐘跺喌鐨勮瀹?

// -------------------------------------------------------------------
//涓撴锛氬疇鐗┿€侀亾鍏风紪鐮?	浜哄憳锛氬皬鐟?
#define _UNIQUE_P_I	        	// (鍙紑鏀? CoolFish 2001/10/11

// -------------------------------------------------------------------
//涓撴锛氭柊鐗堜汉鐗╁偍瀛榩n 鍙?褰撴満涓嶅洖鏈?1018	浜哄憳锛氬溅鍕?
#define _NEWSAVE                // (鍙紑鏀? Robin
#define _STORECHAR              // (鍙紑鏀? Robin
#define _DROPCHECK              // (鍙紑鏀? Robin 闃叉閲嶅涓㈤亾鍏?
#define _DROPCHECK2             // (鍙紑鏀? Robin 闃叉閲嶅涓㈤亾鍏?
// -------------------------------------------------------------------
//涓撴 : 绮剧伒鐜?浜哄憳 : 褰﹁豹
#define _PET_TRANS           	// (鍙紑鏀? 瀹犵墿杞敓鍔熻兘
#define _NEW_WARPMAN        	// (鍙紑鏀? NPC澶氶噸WARP鍔熻兘
#define _PET_TALK	            // (鍙紑鏀? 瀹犵墿瀵硅瘽
#define _PET_LIMITLEVEL	        // (鍙紑鏀? 鐗规畩瀹犺璁?鐜涜暰)
#define _MAP_NOEXIT	            // (鍙紑鏀? 鐗规畩鍦板浘涓嶅緱鍘熺櫥&鍘熺櫥鍥炴寚瀹氱偣
// -------------------------------------------------------------------
// 涓撴锛欸M鎸囦护銆佸眰绾eload		浜哄憳锛氬皬鐟?
#define _GMRELOAD           	// (鍙紑鏀? CoolFish: 2001/11/12
// -------------------------------------------------------------------
// 涓撴锛氫紛鐢稿ぇ闄?浜哄憳锛氬溅璞€侀樋姘戙€佸皬鐟?
#define _GAMBLE_ROULETTE	    // (鍙紑鏀? 褰﹁豹 璧屽満杞洏	瀹濆疂灏忕尓
#define _FIX_GAMBLENUM          // (鍙紑鏀? 杞洏淇 : 涓嬬嚎鎵ｇН鍒?
#define _GAMBLE_BANK	        // (鍙紑鏀? 褰﹁豹  璧屽満閾惰
#define _DROPSTAKENEW	        // (鍙紑鏀? CoolFish:  璧屽満涓嬫敞
#define _PETRACE	            // (鍙紑鏀? CoolFish: 2001/12/3 瀹犵墿绔為€熷満
#define _NEWEVENT               // (鍙紑鏀? CoolFish: 2001/12/5 鏂扮殑浠诲姟鏃楁爣
//#define _BIGSMALL             // (涓嶅彲寮€) Arminius 12.15 楠板瓙姣斿ぇ灏?
//#define _AUCTIONEER           // (涓嶅彲寮€) Arminius 12.20 鎷嶅崠搴?
// -------------------------------------------------------------------
//涓撴锛氶灜鐐埗浣?浜哄憳锛氭檽濞?
#define _ITEM_FIRECRACKER       // (鍙紑鏀? 鎴樻枟涓娇鐢ㄩ灜鐐彲浠ユ妸骞村吔鍚撹蛋
// -------------------------------------------------------------------
//鏂板姛鑳斤細搴勫洯PK瑙勫垯(閰峰摜瀹氱殑)		浜哄憳锛氬織浼熴€佸織鏃?
#define _MANOR_PKRULE           // (鍙紑鏀?
#define _MANOR_FIXFMPK          // (鍙紑鏀? WON ADD 瀹舵棌绾︽垬鐨?GM 鎸囦护锛屾祴璇曠敤鐨?
// -------------------------------------------------------------------
// 鏂板姛鑳斤細鏂板姛鑳?瀹犵墿鎶€鑳?	浜哄憳锛氬溅璞?
#define _PSKILL_FALLGROUND		// (鍙紑鏀? 瀹犵墿鎶€鑳? (钀介┈鏈?
#define _ENEMY_FALLGROUND		// (鍙紑鏀? NPC 钀介┈
#define _BATTLE_NEWPOWER		// (鍙紑鏀?
#define _Item_MoonAct	        // (鍙紑鏀? 鏈堢鐨勫畧鎶?
#define _Item_DeathAct          // (鍙紑鏀? 鎭堕瓟鐨勯楗?
#define _Item_PetAct            // (鍙紑鏀? 椹吔鎴掓寚
#define _Item_ReLifeAct         // (鍙紑鏀? 闇€瑕乮temset1.txt 鎵嶈兘寮€) 鏇胯韩濞冨▋
#define _BATTLESTEAL_FIX        // (鍙紑鏀? 淇鍋风獌
#define _CFREE_petskill         // (鍙紑鏀? 闇€瑕乸etskill1.txt 鎵嶈兘寮€) 鏂板涔犲疇鐗╂妧鑳芥妧鑳?
#define _data_newreadfile       // (鍙紑鏀? 鏂扮殑server setup.cf 妗ｆ 鍖呭惈 itemset1.txt petskill1.txt 涓や釜鏂版。
#define _ITEM_MAXUSERNUM        // (鍙紑鏀? 鏂?itemset1.txt ITEM 浣跨敤娆℃暟
// -------------------------------------------------------------------
//鏂板姛鑳斤細浼婄敻浜屾湡		浜哄憳锛氬溅璞?
#define _PET_TALKPRO      		// (鍙紑鏀? 瀹犵墿瀵硅瘽鍔犲己	& 鏀?END
#define _PRO_NPCFIX	     		// (鍙紑鏀? NPC鍔熻兘鍔犲己
#define _PRO_BATTLEENEMYSKILL	// (鍙紑鏀? 鎴樻枟鍔犲己	鎻愬崌NPC鐨凙I鎶€鑳?
#define _NEW_WARPPOINT		    // (鍙紑鏀? 浼犻€佺偣澶氶噸鏉′欢鍒ゆ柇WARP
#define _FIX_CHECKITEM	      	// (鍙紑鏀? 閬撳叿涓嶅仛闈炴硶妫€鏌?
// -------------------------------------------------------------------
//鏂板姛鑳斤細浼婄敻浜?浜哄憳锛氬皬姘?WON
#define _ADD_ENCOUNT             // (鍙紑鏀? WON 澧炲姞鏁岄伃閬囪Е鍙戜慨浠?
#define _WON_PET_MAIL_LOG		 // (鍙紑鏀? WON 鐜╁瀵勫疇閭?LOG
// -------------------------------------------------------------------
// 鏂板姛鑳斤細浼婄敻鍙佹湡	4.0	浜哄憳锛氬溅璞? 蹇椾紵 , 鍙堣崳 , 蹇楁椇
//#define _LOSE_FINCH_				// (涓嶅彲寮€) ANDY 鏈遍泙鎶€鑳?
#define _FIX_FAMILY_PK_LIMIT	    // (鍙紑鏀? WON 灏嗗彲鎸戞垬搴勫洯鐨勭敱鍓嶅崄澶ф敼涓哄墠浜屽崄澶?
#define _ADD_POOL_ITEM				// (鍙紑鏀? WON 澧炲姞鍙瘎鏀剧殑閬撳叿
#define _ITEM_METAMO                // (鍙紑鏀? shan metamo sprite. code:robin->shan
#define _ENEMY_ATTACK_AI            // (鍙紑鏀? shan enemy attack mode. code:shan
#define _ITEM_TIME_LIMIT            // (鍙紑鏀? shan time limit of item. code:shan
#define _MIND_ICON                  // (鍙紑鏀? shan show icon from char mind. code:shan
#define _BATTLENPC_WARP_PLAYER      // (鍙紑鏀? shan npc warp player when n round. code:shan
#define _ITEM_WARP_FIX_BI           // (鍙紑鏀? shan fix bbi to bi. code:shan
#define _SKILL_DAMAGETOHP			// (鍙紑鏀? ANDY 鍡滆鎶€
#define _Skill_MPDAMAGE				// (鍙紑鏀? ANDY MP浼ゅ
#define _WAEI_KICK					// (鍙紑鏀? ANDY 璺ㄦ槦鐞冭涪浜?
#define _BATTLE_TIMESPEED			// (鍙紑鏀? ANDY 鎴樻枟鏃堕棿 娴嬭瘯(鍖椾含涓嶅繀寮€锛屾尅鍔犻€熷姛鑳?
#define _NEW_RIDEPETS				// (鍙紑鏀? ANDY 鏂伴獞瀹?
#define _FIXBUG_ATTACKBOW			// (鍙紑鏀? ANDY 淇楠戝疇浣跨敤鎶曟幏姝﹀櫒bug
#define _NPCCHANGE_PLAYERIMG		// (鍙紑鏀? ANDY NPC鏀瑰彉鐜╁鍥惧彿, 寮哄埗钀介┈,璁ょ帺瀹跺浘鍙?(娴嬪畬)
#define _ITEM_ATTSKILLMAGIC			// (鍙紑鏀? ANDY 閬撳叿鎶€鑳?
#define _EQUIT_DEFMAGIC				// (鍙紑鏀? ANDY 鎶楅瓟瑁呭
#define _FIX_MAGICDAMAGE			// (鍙紑鏀? ANDY 淇榄旀硶鍏紡 鍙佹湡寮€鏀?
#define _ITEM_CONSTITUTION			// (鍙紑鏀? ANDY 淇涓汉浣撹川
#define _MAGIC_REHPAI				// (鍙紑鏀? ANDY 琛ヨAI
#define _TRANSER_MAN				// (鍙紑鏀? ANDY 浼犻€佸笀
#define _TAKE_ITEMDAMAGE			// (鍙紑鏀? ANDY 閬撳叿鎹熷潖	ITEMSET2
#define _FIX_FIRECRACKER			// (鍙紑鏀? ANDY 淇 闉偖
#define _FIX_ITEMPROB				// (鍙紑鏀? ANDY 淇 鎺夊疂鐜?
#define _ADD_DEAMGEDEFC				// (鍙紑鏀? ANDY 棰濆浼ゅ & 闄勫姞鏀诲嚮	ITEMSET2
#define _FIX_MAXCHARMP				// (鍙紑鏀? ANDY MP涓婇檺
#define _ITEM_INSLAY				// (鍙紑鏀? ANDY 闀跺疂鐭?鍔ㄤ綔
#define _ITEMSET2_ITEM				// (鍙紑鏀? ANDY ITEMSET2
#define _ITEM_NPCCHANGE				// (鍙紑鏀? ANDY 宸ュ尃 (鎻愮偧, 绮惧伐)
#define _PETSKILL_FIXITEM			// (鍙紑鏀? ANDY 淇 && 鍚岄亾鍏锋崯鍧?
#define _FIX_SETWORKINT				// (鍙紑鏀? ANDY (FIXWORKINT)
#define _ITEM_ADDEXP				// (鍙紑鏀? vincent  閬撳叿:鎸囧畾鏃堕棿鍐呭鍔犵粡楠屽€间笂鍗囧箙搴?
#define _ITEM_ADDEXP2				// 鏅烘灉鏃堕棿鍙互绱姞 Robin
#define _FIX_METAMORIDE				// (鍙紑鏀? ANDY
//#define _M_SERVER					// (鍙紑鏀? GM SERVER (鍖椾含&闊╁浗涓嶅繀寮€)
//#define _FIX_MSERVER				// (鍙紑鏀? GM SERVER PROC (鍖椾含&闊╁浗涓嶅繀寮€)
#define _CHECK_ITEMDAMAGE			// (鍙紑鏀? 閬撳叿鎹熷潖淇	7/26
#define _SKILL_WILDVIOLENT_ATT		// (鍙紑鏀? vincent  瀹犳妧:鐙傛毚鏀诲嚮
#define _MAGIC_WEAKEN				// (鍙紑鏀? vincent  绮剧伒:铏氬急
#define _SKILL_WEAKEN				// (鍙紑鏀? vincent  瀹犳妧:铏氬急//闇€瑕佸紑#define _MAGIC_WEAKEN
#define _SKILL_SPEEDY_ATT			// (鍙紑鏀? vincent  瀹犳妧:鐤鹃€熸敾鍑?
#define _SKILL_GUARDBREAK2			// (鍙紑鏀? vincent  瀹犳妧:鐮撮櫎闃插尽2
#define _SKILL_SACRIFICE			// (鍙紑鏀? vincent  瀹犳妧:鏁戞彺
#define _PSKILL_MODIFY				// (鍙紑鏀? ANDY 灞炴€у己鍖栨敾鍑?
#define _PSKILL_MDFYATTACK			// (鍙紑鏀? ANDY 鏀诲嚮杞寲灞炴€?
#define _MAGIC_DEFMAGICATT			// (鍙紑鏀? ANDY 榄旀硶闃插尽
#define _MAGIC_SUPERWALL			// (鍙紑鏀? ANDY 閾佸闃插尽
#define _OTHER_MAGICSTAUTS			// (鍙紑鏀? ANDY
#define _SKILL_TOOTH				// (鍙紑鏀? ANDY   榻挎湳
#define _MAGIC_DEEPPOISON			// (鍙紑鏀? vincent  绮剧伒:鍓ф瘨
#define _MAGIC_BARRIER				// (鍙紑鏀? vincent  绮剧伒:榄旈殰
#define _MAGIC_NOCAST				// (鍙紑鏀? vincent  绮剧伒:娌夐粯
#define _ITEM_CRACKER               // (鍙紑鏀? vincent  閬撳叿:鎷夌偖//闇€瑕佸紑#define _MIND_ICON
#define _SKILL_DEEPPOISON			// (鍙紑鏀? vincent  瀹犳妧:鍓ф瘨//闇€瑕佸紑#define _MAGIC_DEEPPOISON
#define _SKILL_BARRIER				// (鍙紑鏀? vincent  瀹犳妧:榄旈殰//闇€瑕佸紑#define _MAGIC_BARRIER
#define _SKILL_NOCAST				// (鍙紑鏀? vincent  瀹犳妧:娌夐粯//闇€瑕佸紑#define _MAGIC_NOCAST
#define _SKILL_ROAR					// (鍙紑鏀? vincent  瀹犳妧:澶у惣(鍏嬪勾鍏?
#define _SKILL_REFRESH			    // (鍙紑鏀? vincent  瀹犳妧:瑙ｉ櫎寮傚父鐘舵€?
#define _ITEM_REFRESH               // (鍙紑鏀? vincent  瑙ｉ櫎寮傚父鐘舵€侀亾鍏?
#define _MAGIC_TOCALL				// (鍙紑鏀? kjl		 鍙敜	02/06/20 kjl

// -------------------------------------------------------------------
// 鏂板姛鑳斤細鏉ュ悏鍗″姛鑳? 浜哄憳锛氬溅璞?
#define _ITEMSET3_ITEM				// (鍙紑鏀? ANDY itemset3.txt
#define _SUIT_ITEM					// (鍙紑鏀? ANDY (濂楄) 鏉ュ悏鍗?闇€鐢╥temset3.txt
#define _PETSKILL_SETDUCK			// (鍙紑鏀? ANDY 钂欏鎶€鑳?
#define _VARY_WOLF                  // (鍙紑鏀? pet skill : vary wolf. code:shan
// -------------------------------------------------------------------
// 鏂板姛鑳斤細涓撴5.0		浜哄憳锛?
//#define _ITEMTBL_STAIC			// (涓嶅彲寮€) ANDY (闈欐€両TEMTBL)
#define _USEWARP_FORNUM				// (鍙紑鏀? ANDY 璁板繂缇芥瘺 鏉ュ悏鍗?
#define _IMPRECATE_ITEM				// (鍙紑鏀? ANDY 鐗规畩閬撳叿 鏉ュ悏鍗?
#define _MAGICPET_SKILL				// (鍙紑鏀? ANDY 榄旀硶瀹犳妧鑳?
#define _ITEM_CHECKWARES			// (鍙紑鏀? ANDY 閿佸畾浼犻€佷笉鑳?
#define _NPC_REPLACEMENT			// (鍙紑鏀? ANDY 缃崲鎴樻枟npc
#define _EMENY_CHANCEMAN			// (鍙紑鏀? ANDY EMENY 閫夋嫨
#define _TYPE_TOXICATION			// (鍙紑鏀? ANDY 涓瘨鏃犳硶鍥炶
#define _PET_FUSION					// (鍙紑鏀? ANDY 瀹犵墿铻嶅悎 enemybase1.txt
#define _NPC_FUSION					// (鍙紑鏀? ANDY NPC瀹犵墿铻嶅悎
#define _ITEM_EDITBASES				// (鍙紑鏀? ANDY 钀ュ吇鍓?
#define _PET_EVOLUTION				// (鍙紑鏀? ANDY 杩涘寲琛?

// -------------------------------------------------------------------
// 鏂板姛鑳斤細5.0杩藉姞閮ㄥ垎		浜哄憳锛?
#define _AVID_TRADETRYBUG			// (鍙紑鏀? ANDY 闃叉浜ゆ槗涓涪瀹?閬撳叿 瀵?瀹犵墿)閭欢 鐭冲竵
#define _ASSESS_SYSEFFICACY			// (鍙紑鏀? ANDY 璇勪及绯荤粺鏁堣兘 12/04 鏇存柊
#define _ASSESS_SYSEFFICACY_SUB		// (鍙紑鏀? Robin 璇勪及绯荤粺鏁堣兘 澧炲姞妫€鏌ュ唴鍥炲湀
//#define _PREVENT_TEAMATTACK			// (鍙紑鏀? ANDY 闃叉鍚岄槦浜掓墦 12/04 鏇存柊
#define _ITEM_ORNAMENTS				// (鍙紑鏀? ANDY 瑁呴グ閬撳叿	12/04 鏇存柊 //鍑虹増閮?
#define _CHIKULA_STONE				// (鍙紑鏀? ANDY 濂囧厠鎷変箣鐭?12/04 鏇存柊 //鏉ュ悏鍗?瀹犲寘
#define _SEND_EFFECT				// (鍙紑鏀? WON  AC閫佷笅闆€佷笅闆ㄧ瓑鐗规晥 12/04 鏇存柊
#define _PETMAIL_DEFNUMS			// (鍙紑鏀? ANDY 瀹犵墿閭欢闄愬埗
#define _TEAM_KICKPARTY				// (鍙紑鏀? ANDY 闃熼暱韪汉(闈炴垬鏂楃姸鎬?
#define _PETSKILL_TIMID				// (鍙紑鏀? ANDY 瀹犳妧-鎬垬
#define _PETS_SELECTCON				// (鍙紑鏀? ANDY 瀹犵墿涓嶅彲鐐归€夊嚭鎴?
#define _CHRISTMAS_REDSOCKS			// (鍙紑鏀? ANDY 鍦ｈ癁绾㈣
#define _FIX_ARRAYBUG				// (鍙紑鏀? ANDY 淇array 婧綅
#define _USER_CHARLOOPS				// (鍙紑鏀? ANDY 鏂扮敤鐗╀欢LOOP
#define _BATTLE_PROPERTY			// (鍙紑鏀? ANDY 鎴樻枟灞炴€х壒鎬?
#define _PETSKILL_PROPERTY			// (鍙紑鏀? ANDY 鏃犲睘榄斿吔瀹犳妧
#define _ITEM_FIXALLBASE			// (鍙紑鏀? ANDY 淇涔嬬煶
#define _ITEM_LOVERPARTY			// (鍙紑鏀? ANDY 鎯呬汉鑺傞亾鍏?
#define _ITEM_FORUSERNAMES			// (鍙紑鏀? ANDY 閬撳叿鎵€鏈変汉
#define _BATTLECOMMAND_TIME			// (鍙紑鏀? ANDY 闃叉鐜╁寮€缂撻€?鍥炲悎鎴樻枟鏃堕棿)
#define _NPCENEMY_ADDPOWER			// (鍙紑鏀? ANDY 淇敼鎬墿鐨勮兘鍔涘€?
//#define _BAD_PLAYER				// (涓嶅彲寮€) WON  閫佸潖鐜╁鍘诲叧


// -------------------------------------------------------------------
// 鏂板姛鑳斤細涓撴6.0		浜哄憳锛?
//
#define _PETSKILL_CANNEDFOOD		// (鍙紑鏀? ANDY 瀹犵墿鎶€鑳界綈澶?for 6.0
#define _TEST_DROPITEMS				// (鍙紑鏀? ANDY 娴嬭瘯涓㈠疇
#define _MAP_WARPPOINT				// (鍙紑鏀? ANDY Map WarpPoint
//#define _AUTO_ADDADDRESS			// (鍙紑鏀? ANDY 鑷姩鏂板鍚嶇墖
#define _DEFEND_TIMECHECK			// (鍙紑鏀? ANDY 鍐呴儴娴嬭瘯鏃堕棿
#define _TREASURE_BOX				// (鍙紑鏀? ANDY 瀹濈
#define _BENEMY_EVENTRUN			// (鍙紑鏀? ANDY 鎴樻枟npc缁欓亾鍏?
#define _BATTLE_ABDUCTII			// (鍙紑鏀? ANDY 鏃呴€斿ぅ浼?
#define _BATTLE_LIGHTTAKE			// (鍙紑鏀? ANDY 閲囧厜鏈?
#define _BATTLE_ATTCRAZED			// (鍙紑鏀? ANDY 鐤媯鏆磋蛋
#define _STATUS_WATERWORD			// (鍙紑鏀? ANDY 姘翠笘鐣岀姸鎬?
#define _ITEM_WATERWORDSTATUS		// (鍙紑鏀? ANDY 姘翠笘鐣岀姸鎬侀亾鍏?
//#define _KILL_12_STOP_GMSV			// (鍙紑鏀? WON  涓媠igusr2寰屽叧闂璆MSV
//#define _DELBORNPLACE				// (鍙紑鏀? Syu  6.0 缁熶竴鍑虹敓鏂兼柊鎵嬫潙
#define _REEDIT_PETBBIS				// (鍙紑鏀? ANDY 淇瀹犵墿娉㈡瘮鍥惧舰
#define _CAPTURE_FREES				// (鍙紑鏀? ANDY 琛ユ姄鏉′欢
#define _THROWITEM_ITEMS			// (鍙紑鏀? 涓㈡幏寰屾湁濂栧搧
//#define _OBJSEND_C					// (鍙紑鏀? ANDY _OBJSEND_C
//#define _ADD_SHOW_ITEMDAMAGE		// (鍙紑鏀? WON  鏄剧ず鐗╁搧鑰愪箙搴?

//--------------------------------------------------------------------------
//涓撴 7.0	鑱屼笟绯荤粺	浜哄憳锛氬溅璞?蹇楁椇 鏃瘹 濂囬摠

#define _CHANGETRADERULE		    // (鍙紑鏀? Syu ADD 浜ゆ槗瑙勫垯淇
#define _TRADE_SHOWHP				// (鍙紑鏀? Syu ADD 浜ゆ槗鏄剧ず琛€閲?
//#define _SHOOTCHESTNUT				// (鍙紑鏀? Syu ADD 瀹犳妧锛氫涪鏍楀瓙
//#define _SKILLLIMIT					// (鍙紑鏀? Syu ADD 涓嶅緱鏀诲嚮鎴戞柟闄愬埗
//#define _TRADESYSTEM2				// (鍙紑鏀? Syu ADD 鏂颁氦鏄撶郴缁?
//#define _NPC_NOSAVEPOINT			// (鍙紑鏀? ANDY 绾綍鐐逛笉瀛樹汉鐗╄祫鏂?
#define _ACFMPK_LIST				// (鍙紑鏀? ANDY 瀹舵棌瀵规垬鍒楄〃淇
#define _PETSKILL2_TXT				// (鍙紑鏀? ANDY petskill2.txt
#define _PETSKILL_CHECKTYPE			// (鍙紑鏀? ANDY 瀹犵墿鎶€鑳戒娇鐢ㄦ椂鏈?
#define _PETSKILL_TEAR				// (鍙紑鏀? ANDY 瀹犳妧 鎾曡浼ゅ彛
#define _NPC_MAKEPAIR				// (鍙紑鏀? ANDY NPC 閰嶅
#define _ITEMSET4_TXT				// (鍙紑鏀? ANDY itemset4.txt
//#define _ITEM_PILENUMS				// (鍙紑鏀? ANDY 閬撳叿绱犳潗鍫嗗彔 闇€ itemset4
//#define _ITEM_PILEFORTRADE			// (鍙紑鏀? ANDY 浜ゆ槗鍫嗗彔
//#define _ITEM_EQUITSPACE			// (鍙紑鏀? ANDY 鏂拌澶囨爮浣?
#define _PET_LOSTPET				// (鍙紑鏀? ANDY 閬楀け瀹犵墿鎼滃璁″垝瀹犵墿
#define _ITEMSET5_TXT				// (鍙紑鏀? ANDY itemset5.txt
#define _ITEMSET6_TXT				// (鍙紑鏀? ANDY itemset6.txt
#define _EQUIT_ARRANGE				// (鍙紑鏀? ANDY 鎸℃牸 闇€瑕?itemset5.txt
#define _EQUIT_SEQUENCE				// (鍙紑鏀? ANDY 鏀诲嚮椤哄簭 闇€瑕?itemset5.txt
#define _EQUIT_ADDPILE				// (鍙紑鏀? ANDY 澧炲姞鍙爢鍙犳暟 闇€瑕?itemset5.txt
#define _EQUIT_HITRIGHT				// (鍙紑鏀? ANDY 鍛戒腑 闇€瑕?itemset5.txt
#define _EQUIT_NEGLECTGUARD			// (鍙紑鏀? ANDY 蹇借鐩爣闃插尽鍔? 闇€瑕?itemset6.txt
//#define _EQUIT_NEWGLOVE				// (鍙紑鏀? ANDY 鎵嬪鏍忎綅
#define _FM_JOINLIMIT				// (鍙紑鏀? ANDY 鍔犲叆瀹舵棌鏉′欢闄愬埗
#define _FIX_MAX_GOLD				// (鍙紑鏀? WON ADD 澧炲姞浜虹墿閲戦挶涓婇檺
#define _CK_ONLINE_PLAYER_COUNT		// (鍙紑鏀? WON 璁＄畻绾夸笂浜烘暟 (瑕侀厤鍚坅c锛屽惁鍒欎細閲嶅紑)
#define _PET_SKILL_SARS				// (鍙紑鏀? WON ADD 姣掔厼钄撳欢
#define _SONIC_ATTACK				// (鍙紑鏀? WON ADD 闊虫尝鏀诲嚮
#define _NET_REDUCESEND				// (鍙紑鏀? ANDY 鍑忓皯DB璧勬枡浼犻€?
#define _FEV_ADD_NEW_ITEM			// (鍙紑鏀? Change 澧炲姞澶嶆椿瀹堢簿
#define _ALLDOMAN					// (鍙紑鏀? Syu ADD 鎺掕姒淣PC
#define _LOCKHELP_OK				// (鍙紑鏀? Syu ADD 閿佸畾涓嶅彲鍔犲叆鎴樻枟
//#define _TELLCHANNEL				// (鍙紑鏀? Syu ADD 瀵嗚棰戦亾
// 鏂板姛鑳斤細鑱屼笟
#define _NEWREQUESTPROTOCOL			// (鍙紑鏀? Syu ADD 鏂板Protocol瑕佹眰缁嗛」
#define _OUTOFBATTLESKILL			// (鍙紑鏀? Syu ADD 闈炴垬鏂楁椂鎶€鑳絇rotocol
//#define _CHAR_PROFESSION			// (鍙紑鏀? WON ADD 浜虹墿鑱屼笟鏍忎綅
//#define _PROFESSION_SKILL			// (鍙紑鏀? WON ADD 浜虹墿鑱屼笟鎶€鑳?
//#define _NPC_WELFARE				// (鍙紑鏀? WON ADD 鑱屼笟NPC
//#define _PROFESSION_FIX_LEVEL		// (鍙紑鏀? WON ADD 淇鑱屼笟缁忛獙鍊?鍖椾含&闊╁浗涓嶅繀寮€)
#define _GM_SIGUSR2					// (鍙紑鏀? Change 涓嬭揪sigusr2寰屾墽琛?gm_sigusr_command妗ｆ鍐呯殑GM鎸囦护,鑻ユ病鏈夋寚浠ゅ氨鍏抽棴GMSV
#define _GM_BROADCAST				// (鍙紑鏀? WON ADD 瀹㈡湇鍏憡绯荤粺
#define _NPC_ADDLEVELUP				// (鍙紑鏀? ANDY NPC澧炲姞鐜╁绛夌骇
#define _CHAR_FIXDATADEF			// (鍙紑鏀? ANDY 淇浜虹墿璧勬枡鍒濆
//绯荤粺鏀硅壇
#define _SIMPLIFY_ITEMSTRING		// (鍙紑鏀? ANDY 绠€鍖栭亾鍏峰瓧涓?
#define _CHAR_NEWLOGOUT				// (鍙紑鏀? ANDY 鐧诲嚭鏂版満鍒?
//#define _CHATROOMPROTOCOL			// (鍙紑鏀? Syu ADD 鑱婂ぉ瀹ら閬?8/27

#define _CHAR_POOLITEM				// (鍙紑鏀? ANDY 浜虹墿閬撳叿浠撳簱鍏辩敤
#define _NPC_DEPOTITEM				// (鍙紑鏀? ANDY 浜虹墿閬撳叿浠撳簱鍏辩敤

//#define _SIMPLIFY_PETSTRING			// (鍙紑鏀? ANDY 绠€鍖栧疇鐗╁瓨妗ｅ瓧涓?
#define _SIMPLIFY_ITEMSTRING2		// (鍙紑鏀? ANDY 绠€鍖栭亾鍏峰瓧涓?
#define _WOLF_TAKE_AXE				// (鍙紑鏀? WON ADD 鎶撳弻澶寸嫾鐨勯檺鍒?
#define _FIX_UNNECESSARY			// (鍙紑鏀? ANDY 淇涓嶅繀瑕佺殑鍒ゆ柇
#define _ITEM_MAGICRECOVERY			// (鍙紑鏀? ANDY 鏂板厜闀滃畧
//9/17鏇存柊
#define _PETSKILL_GYRATE			// (鍙紑鏀? Change 瀹犳妧:鍥炴棆鏀诲嚮
#define _PETSKILL_ACUPUNCTURE		// (鍙紑鏀? Change 瀹犳妧:閽堝埡澶栫毊 (client绔殑_PETSKILL_ACUPUNCTURE涔熻寮€)
#define _PETSKILL_RETRACE			// (鍙紑鏀? Change 瀹犳妧:杩借抗鏀诲嚮
#define _PETSKILL_HECTOR			// (鍙紑鏀? Change 瀹犳妧:濞佸悡
//10/13鏇存柊
#define _PETSKILL_FIREKILL			// (鍙紑鏀? Change 瀹犳妧:鐏嚎鐚庢潃
#define _PETSKILL_DAMAGETOHP		// (鍙紑鏀? Change 瀹犳妧:鏆楁湀鐙傜嫾(鍡滆鎶€鐨勫彉浣?
#define _PETSKILL_BECOMEFOX         // (鍙紑鏀? Change 瀹犳妧:濯氭儜鏈?
//10/22鏇存柊
// 鏂板姛鑳斤細淇敼WORKER(鏂颁粯璐规満鍒?
#define _FIX_MESSAGE				// (鍙紑鏀? WON ADD 淇敼WORKER灏佸寘鍐呭 (鍖椾含&闊╁浗涓嶅繀寮€)

//11/12鏇存柊
#define _PETSKILL_SHOWMERCY         // (鍙紑) Change 瀹犳妧:鎵嬩笅鐣欐儏
#define _NPC_ActionFreeCmp          // (鍙紑) Change 鏇縉PC鍙傛暟鍔犲叆鏂扮殑姣旇緝鏂瑰紡
//--------------------------------------------------------------------------


//11/26
#define _NPC_ProfessionTrans      // (鍙紑) Change 鏇胯亴涓歂PC鍔犲叆鍒ゆ柇杞敓
#define _NPC_NewDelPet            // (鍙紑) Change 鏇縉PC鍔犲叆鍒犻櫎瀹犵墿(鍘熸湰灏辨湁浜?鍙槸鐢╳arpman浣跨敤鏃朵笉鎴愬姛,鎵€浠ュ厛鍋氫竴涓《涓€涓?
//#define _MUSEUM // 鐭冲櫒鍗氱墿棣? Robin 2003/11
	#ifdef _MUSEUM
	#define _DELBORNPLACE
	#endif
#define _CHANGEGALAXY	// (鍙紑) 鏄熺郴绉绘皯銆€Robin 2003/10
#define _ALLDOMAN_DEBUG           // (鍙紑) Change 淇閲嶅惎server寰屾帓琛屾娑堝けbug
//20031217
#define _CHRISTMAS_REDSOCKS_NEW	  // (鍙紑) Change 鏂板湥璇炵孩琚?
#define _PETSKILL_COMBINED      // (鍙紑) Change 瀹犳妧:闅惧緱绯婃秱 [缁煎悎榄旀硶(渚濆弬鏁颁贡鏁板彇鍑洪瓟娉?]
//鎯呬汉鑺傛椿鍔?
#define _NPC_ADDWARPMAN1			// (鍙紑鏀? Change npcgen_warpman澧炲姞鍔熻兘(璁惧畾缁勯槦浜烘暟銆佽瀹氱粍闃熺敺濂充汉鏁?
#define _ITEM_QUITPARTY			// (鍙紑鏀? Change 闃熶紞瑙ｆ暎鏃剁壒瀹氶亾鍏峰嵆浼氭秷澶?
#define _ITEM_ADDEQUIPEXP       // (鍙紑) Change 瑁呭寰岀粡楠屽€煎鍔?
//2004/2/18
#define _ITEM_LVUPUP            // (鍙紑) Change 绐佺牬瀹犵墿绛夌骇闄愬埗鐨勮嵂(鐜勬涓撶敤)
//2004/02/25
//#define _PETSKILL_BECOMEPIG     // (鍙紑) Change 瀹犳妧:涔屽姏鍖?
//#define _ITEM_UNBECOMEPIG       // (鍙紑) Change 涔屽姏鍖栫殑瑙ｈ嵂
#define _PET_TALKBBI            // (鍙紑) Change 澧炲姞鍒ゆ柇bbi
#define _ITEM_USEMAGIC			// (鍙紑) Change 鐢遍亾鍏蜂娇鐢ㄩ瓟娉?
//2004/04/07
#define _ITEM_PROPERTY          // (鍙紑) Change 鏀瑰彉鍥涘睘鎬ч亾鍏?
#define _SUIT_ADDENDUM          // (鍙紑) Change 鏇垮瑁呭鍔犲姛鑳?(_SUIT_ITEM瑕佸紑)
//2004/05/05
#define _ITEM_CHECKDROPATLOGOUT   // (鍙紑) Change 妫€鏌ュ洖绾綍鐐规椂韬笂鏈夋棤鐧诲嚭寰屾秷澶遍亾鍏?鑻ユ湁,涓嶅彲鍥炵邯褰曠偣
//#define _FM_MODIFY				// 瀹舵棌鍔熻兘淇敼(寮€鏀?
//#define _CHANNEL_MODIFY		// 棰戦亾鍔熻兘鏁村悎(寮€鏀?
#define _STANDBYPET		// Robin 寰呮満瀹犲皝鍖?
//#define	_PROSKILL_OPTIMUM	// Robin 鑱屼笟鎶€鑳藉鐞嗘渶浣冲寲
#define	_PETSKILL_OPTIMUM	// Robin 瀹犵墿鎶€鑳藉鐞嗘渶浣冲寲
#define _MAGIC_OPTIMUM		// Robin Magic table 鏈€浣冲寲
#define _AC_PIORITY		// Nuke 鎻愰珮AC鐨勪紭鍏堟潈(鍙紑)
//2004/05/12
#define _CHAR_POOLPET				// (鍙紑鏀? Robin 浜虹墿瀹犵墿浠撳簱鍏辩敤
#define _NPC_DEPOTPET				// (鍙紑鏀? Robin 浜虹墿瀹犵墿浠撳簱鍏辩敤
#define _TIMEOUTKICK	// (鍙紑) 鏃舵鍒惰涪浜恒€€Robin 2003/10
//#define _MAGIC_RESIST_EQUIT			// (鍙紑) WON ADD 鑱屼笟鎶楁€ц澶?
#define _LOG_OTHER // 鏉傞」璁伅涓撶敤LOG

//--------------------------------------------------------------------------
//鏈哄姩钀ユ祴璇曚腑


// -------------------------------------------------------------------
//#define _NPC_QUIZSCOPE          // (涓嶅彲寮€) Change 鏇縉PC澧炲姞棰樺彿  鍥村弬鏁?
//#define _ITEM_ADDCOMBO          // (涓嶅彲寮€) Change 瑁呭寰屽悎鍑荤巼澧炲姞(鎴樺満涓婅鏈?涓汉浠ヤ笂甯︽墠鏈夌敤)鏈畬鎴?..
//#define _NPC_AIRDELITEM         // (涓嶅彲寮€) Change 鎼姞缇庤埅绌烘椂鎵€鎵ｉ櫎鐨勯亾鍏?灏辨槸椋炴満绁ㄥ暒)
//#define _NPC_AIRLEVEL           // (涓嶅彲寮€) Change 鎼姞缇庤埅绌虹殑鏈€澶ф渶绛夌骇闄愬埗(绛夌骇杩囬珮涓嶇粰鎼?

//#define _ANDYLOG_TEST
//#define _NPC_WELFARE_2			// (涓嶅彲寮€) WON ADD 鑱屼笟NPC-2
//#define _UNIVERSE_CHATROOM			// (涓嶅彲寮€) ANDY 鍏ㄦ槦绯昏亰澶?
//#define _FIX_ALLDOMAN				// (涓嶅彲寮€) ANDY 淇鑻遍泟鎴樺満
//鍒朵綔涓?
//#define _SEND_PROF_DATA			// (涓嶅彲寮€) ANDY ADD 浼犻€佽亴涓氭洿鏂扮粰cli
//#define _AUCPROTOCOL				// (涓嶅彲寮€) Syu ADD 鎷嶅崠棰戦亾寮€鍏砅rotocol
//#define _NPC_SELLSTH				// (涓嶅彲寮€) ANDY 鎷嶅崠绯荤粺
//#define _NPC_SEPARATEDATA			// (涓嶅彲寮€) ANDY NPC 璧勬枡鍒嗙

//------------------------------------------------------------------------
// 浠ヤ笅涓哄喕缁撳姛鑳?
//------------------------------------------------------------------------
//#define fix_login_event			// (涓嶅彲寮€) WON 琛ュ洖浼婄敻涓€鏈熺殑澹版湜 (鍖椾含涓嶅繀寮€)
//#define _FIX_DEL_MAP				// (涓嶅彲寮€) WON 鐜╁鎶藉湴鍥鹃€佺洃鐙?
//#define _PETFIGHT					// (涓嶅彲寮€) 瀹犵墿绔炴妧鍦?
//#define _EXM_RANDITEM				// (涓嶅彲寮€) NPC (Exchangeman) 涔辨暟瑕佹眰鐗╁搧 (宸插彇娑?
//#define add_amulet_map			// (涓嶅彲寮€) WON 澧炲姞澶槼绁為楗扮殑  鍥?
//#define _ACFMPK_NOFREE			// (涓嶅彲寮€) ANDY 瀹舵棌鏃犳潯浠?
//--------------------------------------------------------------------------
// 6.0杩藉姞鍔熻兘 pile

//#define _IMPOROVE_ITEMTABLE		// (涓嶅彲寮€) ANDY 鏀瑰杽ITEM TABLE
//#define _NPC_SHOPALTER01			// (涓嶅彲寮€) Change 涔板崠绯荤粺淇敼(閰嶅悎Client鏀逛负鍥惧舰浠嬮潰鎵€鍋氱殑淇敼)
//#define _GM_IDENTIFY				// (涓嶅彲寮€) Change 鏄惁绉€鍑篏M澶撮《涓婅瘑鍒瓧涓茬殑GM鎸囦护
//#define _GSERVER_RUNTIME          // (涓嶅彲寮€) Change 浼犻€丟SERVER鎵ц澶氬皯鏃堕棿缁橫server (Mserver瑕侀厤鍚?
//#define _NPC_VERYWELFARE			// (涓嶅彲寮€) Change 闈炲父濂藉悍A鐨凬PC
//--------------------------------------------------------------------------
//#define _ADD_NEWEVENT             // (涓嶅彲寮€) WON 澶氬浠诲姟鏃楁爣
//#define _BLACK_MARKET				// (涓嶅彲寮€) shan a black market. code:shan
//#define _DYNAMIC_BUILDER_MAP		// (涓嶅彲寮€) shan (test)dynamic builder on the upper map. code:shan
//#define _TEST_ITEMMEMORY			// (涓嶅彲寮€) ANDY (娴嬭瘯ITEMTABL)
//#define _LASTERR_FUNCTION			// (涓嶅彲寮€) ANDY (lastFunction)
//#define _MARKET_TRADE				// (涓嶅彲寮€) ANDY 浜ゆ槗甯傞泦
//#define _PAUCTION_MAN				// (涓嶅彲寮€) ANDY
//#define _SKILL_SELFEXPLODE		// (涓嶅彲寮€) vincent  瀹犳妧:鑷垎(缂哄浘)
//#define _ADD_FAMILY_TAX			// (涓嶅彲寮€) WON 澧炲姞搴勫洯绋庢敹 (瑕侀厤鍚坅c锛屽惁鍒欎細閲嶅紑)
//#define _SYUTRY
/* -------------------------------------------------------------------
 * 鏂板姛鑳斤細PK鏄熺郴 1121 浜哄憳锛氬溅鍕?灏忛噾
 */
//#define _PKPETSHOP				// (涓嶅彲寮€)

// -------------------------------------------------------------------
//鐗规畩娲诲姩鍔熻兘
//#define _CHECK_GAMESPEED			// (涓嶅彲寮€) ANDY 鍔犻€熸娴?
//#define _NPCSERVER_NEW			// (涓嶅彲寮€) ANDY NPC 浼烘湇鍣?
//#define _OBJS_TALKFUN				// (涓嶅彲寮€) ANDY TALK 鎼滃娉?
//#define _NEWOPEN_MAXEXP			// (涓嶅彲寮€) ANDY MAX缁忛獙鍊?
//#define _MERGE_LOG				// (涓嶅彲寮€) ANDY 鍚堟垚 LOG
//#define _CHECK_UCODE				// (涓嶅彲寮€) ANDY 妫€鏌?

//#define _DEATH_FAMILYCONTEND		// (涓嶅彲寮€) ANDY 瀹舵棌鎴樻姤鍚?

//#define _NEW_INSERVERPOINT		// (涓嶅彲寮€) ANDY 鐧诲叆搴ф爣
//#define _DEATH_CONTENDWATCH		// (涓嶅彲寮€) ANDY 鍐虫枟瑙傜湅
//#define _DEATH_CONTENDTEST		// (涓嶅彲寮€) ANDY 姝绘枟璧涚▼鍔犲揩

//#define _DEATH_FAMILY_GM_COMMAND	// (鍙紑) WON ADD 瀹舵棌鎴楪M鎸囦护
//#define _DEATH_FAMILY_LOGIN_CHECK	// (鍙紑) WON ADD 瀹舵棌鎴樼櫥鍏ユ鏌?
//#define _DEATH_FAMILY_STRUCT		// (鍙紑) WON ADD 瀹舵棌鎴樺瓨鏀捐儨璐熻祫鏂?
//#define _DEATH_FAMILY_CANT_SCHEDULE // (鍙紑) WON ADD 瀹舵棌鎴樼帺瀹朵笉鑳借嚜琛岀害鎴?

//#define _ACTION_BULLSCR			// (涓嶅彲寮€) ANDY 铔墰&鏈遍泙 娲诲姩鍔熻兘 (7/30浠ュ緦鎵嶈兘鍏抽棴)
//#define _BULL_FIXPLAYER			// (涓嶅彲寮€) ANDY 淇浜虹墿铔墰娲诲姩鍔熻兘
//#define _BULL_CUTBULLSCR			// (涓嶅彲寮€) ANDY 缁堟铔墰娲诲姩绉垎
//#define _ACTION_GMQUE				// (涓嶅彲寮€) ANDY GM娲诲姩鍔熻兘 姘镐繚鐣?
//#define _PET_FUSIONSHOWTIME		// (涓嶅彲寮€) ANDY 瀹犵墿铔嬬鏃堕棿

//#define _NEW_PLAYERGOLD			// (鍙紑鏀? ANDY 鏂板笎鍙风粰閽?
// -------------------------------------------------------------------
//鐧诲叆妫€鏌ュ姩浣?

//#define _FIX_TSKILLCAN			// (鍙紑鏀? ANDY 淇瀹犵墿T鎶€缃愬ご 浠ュ強 娓呴櫎T瀛楁妧(闈炴満鏆?
//#define _CHANGEGOATMETAMO			// (鍙紑鏀? Syu  缇婂勾鍏芥洿鎹㈡柊鍥?

// -------------------------------------------------------------------
// 鏂板姛鑳斤細GM瀵嗛鍔熻兘鎵╁厖
//#define _GM_WARP_PLAYER			// (涓嶅彲寮€)	WON 浼犻€佺帺瀹?(鍖椾含&闊╁浗涓嶅繀寮€)
//#define _RECAL_ASK_PLAYER			// (涓嶅彲寮€) WON 瑕佹眰浜虹墿璧勬枡 (鍖椾含&闊╁浗涓嶅繀寮€)
//#define _RECAL_SEND_COUNT			// (涓嶅彲寮€) WON 浼犻€丟S璧勮 (鍖椾含&闊╁浗涓嶅繀寮€)
//#define _RECAL_SERVER_OFF			// (涓嶅彲寮€) WON MSERVER 鍏抽棴 GS	(鍖椾含&闊╁浗涓嶅繀寮€)


//#define	_ENEMYTEMP_OPTIMUM	// Robin EnemyBase table 鏈€浣冲寲
//#define	_ENEMY_OPTIMUM		// Robin Enemy table 鏈€浣冲寲
//#define	_CHECK_BATTLETIME	// Robin 绾綍姣忎竴鎴樻枟鎸囦护鏃堕棿(娴嬭瘯鐢?
//#define	_CHECK_BATTLE_IO	// Robin 绾綍鎴樻枟灏佸寘浼犻€?娴嬭瘯鐢?


//澶嶅埢鐗?
//#define _BACK_VERSION	//澶嶅埢鐗?
//#define _REDHAT_V9 //(鍙紑) Change 鍦≧EDHAT9.0鐨勭増鏈笅缂栬瘧鏃舵墦寮€
//#define _UN_FMPOINT // (鍙紑) Change 鍏虫帀鐢宠瀹舵棌鎹偣
//#define _UN_FMMEMO //(鍙紑)Change  鍏虫帀瀹舵棌涔嬮棿鐣欒█鏉?
//--------------------------------------------------------------------------
//涓撴 7.5	绮剧伒鐨勬嫑鍞?浜哄憳锛氬溅鍕?濂囬摠 灏忓▉
#define _NPC_EXCHANGEMANTRANS   // (鍙紑) Change 鏇縠xchangeman鍔犲叆鍒ゆ柇杞敓
//#define	_ANGEL_SUMMON	// Robin 澶╀娇鍙敜
//	#ifdef _ANGEL_SUMMON
//	#define _ADD_NEWEVENT
//	#endif
// Terry define start -------------------------------------------------------------------
//#define _STREET_VENDOR		// 鎽嗘憡鍔熻兘(寮€鏀?
//#define _WATCH_EVENT			// 鏌ヨ浠诲姟鍔熻兘(寮€鏀?
//#define _NEW_MANOR_LAW		// 鏂板簞鍥鍒?寮€鏀?
#define _MAP_TIME					// 鐗规畩鍦板浘,浼氬€掓暟(寮€鏀?
//#define _PETSKILL_LERopen			// 闆峰皵鎶€鑳?寮€鏀?
//#define _TEACHER_SYSTEM		// 瀵煎笀绯荤粺(涓嶅紑鏀?
// Terry define end   -------------------------------------------------------------------
//#define _FIX_MAGIC_RESIST				// (鍙紑) Change 鑱屼笟榄旀硶鎶楁€?
#define _ADD_DUNGEON					// (鍙紑) Change 杩藉姞鍦扮墷
//#define _PROFESSION_ADDSKILL			// (鍙紑) Change 杩藉姞鑱屼笟鎶€鑳?
#define _ITEM_ADDPETEXP				// (鍙紑) Change 澧炲姞瀹犵墿缁忛獙鍊奸亾鍏?鍙悆姝ら亾鍏峰疇鐗?骞冲父涓嶅彲鑾峰緱缁忛獙鍊?
//#define _TRANS_6						// (鍙紑) Change 浜虹墿6杞?
//#define _PET_2TRANS					// (鍙紑) Change 瀹犵墿2杞?
//#define _PET_2LIMITLEVEL				// (鍙紑) Change 甯姪瀹犵墿2杞殑鐜涜暰
//#define _MAGICSTAUTS_RESIST			// (鍙紑) Change (鐏數鍐?鎶楁€х簿鐏?
//#define _EQUIT_RESIST					// (鍙紑) Change 鍗曚竴瑁呭鎶楁€?鍙姉鍗曚竴鍔熻兘寮傚父鐘舵€?鏈夋姉鐏?闆?鍐?铏氬急 榄旈殰 娌夐粯 钀介┈
//#define _SUIT_TWFWENDUM				// (鍙紑) Change 鍥涘睘鎬у瑁呭姛鑳?(_SUIT_ITEM瑕佸紑)
#define _EXCHANGEMAN_REQUEST_DELPET	// (鍙紑) Change 鏇縠xchangeman鐨凾YPE:REQUEST澧炲姞鍒犻櫎瀹犵墿
//#define _75_TEST						// (涓嶅彲寮€) 7.5娴嬭瘯server
//#define _PK_SERVER //鐧句竾pk娲诲姩
//#define _DEATH_CONTEND			// (鍙紑) 鐧句竾pk娲诲姩 ANDY 姝绘枟
//#define _DEATH_CONTENDAB			// (鍙紑) 鐧句竾pk娲诲姩 ANDY 姝ｅ紡姝绘枟
//--------------------------------------------------------------------------

//#define _ESCAPE_RESET			// 鎭跺疂閫冭窇寰屾殏鏃朵笉鍙粍闃? Robin 2004/07/22
#define _DEL_DROP_GOLD			// 鍒犻櫎鍦颁笂杩囨椂鐨勭煶甯?Robin
#define _ITEM_STONE				// cyg 濂囨€殑鐭冲ご
#define _HELP_NEWHAND			// cyg 鏂板垱瑙掕壊缁欎簣鏂版墜閬撳叿) 07.4.5鍚変粩淇敼 鐢ㄤ簬CF璁剧疆鍒涘缓鏂颁汉鎵€閫侀亾鍏穒tem1-item15
#define _DEF_FMFREETIME			// cyg GM鎸囦护 閫€鍑哄鏃忔椂闂撮檺鍒惰涓?
#define _DEF_GETYOU				// cyg GM鎸囦护 鏌ヨ鑷繁涓ゆ牸  鍥村唴鐨勭帺瀹跺笎鍙?
#define _DEF_NEWSEND			// cyg GM鎸囦护 浼犻€佺帺瀹舵椂鍙姞鍙ュ瓙涔熷彲涓嶅姞
#define _DEF_SUPERSEND			// cyg GM鎸囦护 鍙紶閫佸凡鏌愬笎鍙蜂负涓績闄勮繎3鏍煎唴鎵€鏈夌帺瀹?
#define _SUIT_ADDPART3			// (鍙紑) Change 濂楄鍔熻兘绗弫寮?鍥為伩鎻愰珮% 娌夐粯鎶楁€ф彁楂? 鏁忔彁楂? 闃叉彁楂? 鏀绘彁楂?
#define _PETSKILL_2TIMID		// (鍙紑) Change 鎬垬绗簩鐗?鐙傜嫯鎬掑惣)
#define CAVALRY_DEBUG			// (鏆傛椂寮€) Change 搴ч獞鏀诲嚮闄ら敊涓?
//#define _SHOW_FUSION			// (鍙紑) Change 铻嶅悎瀹犵墿鍦–LIENT绔彧鏄剧ず杞敓鏁?淇敼涓鸿瀺鍚堝疇鏄剧ず涓鸿瀺鍚?client绔篃瑕佸紑)
#define _CONTRACT				// (鍙紑) Robin 濂戠害鍔熻兘
//#define _FONT_SIZE				// (鍙紑) Robin 瀛楀瀷澶у皬鍔熻兘
#define _PROSK99				// (鍙紑) Change 妫€鏌ヨ亴鎶€绛夌骇閫佺櫧鐙?
#define _TIME_TICKET			// Robin 闄愭椂鍏ュ満 妫灄鎹夊疇鐢?
#define _HALLOWEEN_EFFECT		// 涓囧湥鑺傜壒鏁?
#define _ADD_STATUS_2			// 鏂板浼犻€佷汉鐗╃姸鎬佺浜岀被
#define _ADD_reITEM				// (鍙紑) Change 妫€鏌ラ亾鍏锋爮浣嶇┖鏍?
#define _ADD_NOITEM_BATTLE		// 鏂板NPC妫€鏌ヤ汉鐗╄韩涓婃病閬撳叿浼氳繘鍏ユ垬鏂?
#define _PETSKILL_BATTLE_MODEL	// 瀹犵墿鎶€鑳芥垬鏂楁ā缁?
#define _RACEMAN				// cyg 鐚庡疇澶т細鏂皀pc
#define _PETSKILL_ANTINTER		// (鍙紑) Change 瀹犳妧:铓佷箣钁?鍙傝€僟PETSKILL_2TIMID
#define _PETSKILL_REGRET		// (鍙紑) Change 瀹犳妧:鎲剧敳涓€鍑?鍙傝€僟SONIC_ATTACK
#define _SUIT_ADDPART4			// (鍙紑) Change 濂楄鍔熻兘绗洓寮?涓瘨鏀诲嚮% 鍔犲己娉曞笀榄旀硶(鏈虹巼30%) 鎶垫姉娉曞笀鐨勯瓟娉?

//#define _STONEAGEA8XXX_S						//鍚変粩 8.0寮€鍏?
//#ifdef _STONEAGEA8XXX_S
//#define _CHECK_ENEMY_PET		// (涓嶅彲寮€) Change 妫€鏌ョ帺瀹舵槸鍚︽寔鏈変笉鍙綋瀹犵墿鐨勮鑹?enemy.txt鐨刾etflg鏍忎綅涓?浠ｈ〃涓嶅彲鎷挎潵褰撳疇鐗?
//#define _ITEM_TYPETABLE		// (涓嶅彲寮€) Change 杩藉姞typetable
//#define _MERGE_NEW_8			// Robin 8.0鐗?鏂板悎鎴愯鍒?
//#define _RIGHTCLICK			// Robin 婊戦紶鍙抽敭鍔熻兘
//#define _JOBDAILY				// cyg 浠诲姟鏃ュ織鍔熻兘
//#define	_ALCHEMIST			// Robin 绮? 鍔熻兘
//#define _CHECK_ITEM_MODIFY	// 妫€鏌ュ紓甯稿姞寮虹殑閬撳叿
//#define _PETSKILL_EXPLODE		// (涓嶅彲寮€) Change 瀹犳妧:鐖嗚鏀诲嚮
//#define _ITEM_S_TEMP						//鍚変粩 8.0閬撳叿灏佸寘鏀寔锛屾鍔熻兘涓轰复鏃跺姛鑳?
//#endif
#define _JZ_NEW_CONF						//鍚変粩 ADD 鏂癈F瀛楁 (涓嶅寘鎷垱寤轰汉鐗╅€侀亾鍏峰瓧娈?
#define _JZ_NEW_GMCOMMAND				//鍚変粩 ADD 鏂癎M鎸囦护
#define _JZ_IMPROVE_GMCOMMAND		//鍚変粩 ADD 鏀硅繘GM鎸囦护
#define _JZ_NEW_ITEM1						//鍚変粩 ADD 鏂板閬撳叿
#define _JZ_NEW_ADDMEMBERPOINT	//鍚変粩 ADD 浼氬憳鐐瑰嵎
//#define _JZ_MANORTES						//搴勫洯娴嬭瘯60绉掑嚭鎴樹功骞跺幓鎺?锛?0-11锛?0涓嬩功闄愬埗
#define _JZ_MANOR_FIX_DFW				//鍚変粩淇敼鍥哄畾鏃堕棿涓嬫垬涔?
#endif