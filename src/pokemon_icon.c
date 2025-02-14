#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "constants/pokemon_icon.h"

#define INVALID_ICON_SPECIES SPECIES_NONE // @@@

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

const u8 *const gMonIconTable[] =
{
    [SPECIES_NONE] = gMonIcon_CSanae,
    [SPECIES_CSANAE] = gMonIcon_CSanae,
    [SPECIES_SANAE] = gMonIcon_Sanae,
    [SPECIES_CALICE] = gMonIcon_CAlice,
    [SPECIES_ALICE] = gMonIcon_Alice,
    [SPECIES_CREISEN] = gMonIcon_CReisen,
    [SPECIES_REISEN] = gMonIcon_Reisen,
    [SPECIES_CLILYWHITE] = gMonIcon_CLilyWhite,
    [SPECIES_LILYWHITE] = gMonIcon_LilyWhite,
    [SPECIES_CLILYBLACK] = gMonIcon_CLilyBlack,
    [SPECIES_LILYBLACK] = gMonIcon_LilyBlack,
    [SPECIES_CMOMIJI] = gMonIcon_CMomiji,
    [SPECIES_MOMIJI] = gMonIcon_Momiji,
    [SPECIES_CSHIZUHA] = gMonIcon_CShizuha,
    [SPECIES_SHIZUHA] = gMonIcon_Shizuha,
    [SPECIES_CMEDICINE] = gMonIcon_CMedicine,
    [SPECIES_MEDICINE] = gMonIcon_Medicine,
    [SPECIES_CKOAKUMA] = gMonIcon_CKoakuma,
    [SPECIES_KOAKUMA] = gMonIcon_Koakuma,
    [SPECIES_CNAZRIN] = gMonIcon_CNazrin,
    [SPECIES_NAZRIN] = gMonIcon_Nazrin,
    [SPECIES_CTOKIKO] = gMonIcon_CTokiko,
    [SPECIES_TOKIKO] = gMonIcon_Tokiko,
    [SPECIES_CREMILIA] = gMonIcon_CRemilia,
    [SPECIES_REMILIA] = gMonIcon_Remilia,
    [SPECIES_CCIRNO] = gMonIcon_CCirno,
    [SPECIES_CIRNO] = gMonIcon_Cirno,
    [SPECIES_CRUMIA] = gMonIcon_CRumia,
    [SPECIES_RUMIA] = gMonIcon_Rumia,
    [SPECIES_SHANGHAI] = gMonIcon_Shanghai,
    [SPECIES_CFLANDRE] = gMonIcon_CFlandre,
    [SPECIES_FLANDRE] = gMonIcon_Flandre,
    [SPECIES_HOURAI] = gMonIcon_Hourai,
    [SPECIES_CYOUMU] = gMonIcon_CYoumu,
    [SPECIES_YOUMU] = gMonIcon_Youmu,
    [SPECIES_CYUKARI] = gMonIcon_CYukari,
    [SPECIES_YUKARI] = gMonIcon_Yukari,
    [SPECIES_CSUIKA] = gMonIcon_CSuika,
    [SPECIES_SUIKA] = gMonIcon_Suika,
    [SPECIES_CMYSTIA] = gMonIcon_CMystia,
    [SPECIES_MYSTIA] = gMonIcon_Mystia,
    [SPECIES_CMINORIKO] = gMonIcon_CMinoriko,
    [SPECIES_MINORIKO] = gMonIcon_Minoriko,
    [SPECIES_CKEINE] = gMonIcon_CKeine,
    [SPECIES_KEINE] = gMonIcon_Keine,
    [SPECIES_AKEINE] = gMonIcon_AKeine,
    [SPECIES_CIKU] = gMonIcon_CIku,
    [SPECIES_IKU] = gMonIcon_Iku,
    [SPECIES_CKOISHI] = gMonIcon_CKoishi,
    [SPECIES_KOISHI] = gMonIcon_Koishi,
    [SPECIES_CYAMAME] = gMonIcon_CYamame,
    [SPECIES_YAMAME] = gMonIcon_Yamame,
    [SPECIES_CCHEN] = gMonIcon_CChen,
    [SPECIES_CHEN] = gMonIcon_Chen,
    [SPECIES_CYORIHIME] = gMonIcon_CYorihime,
    [SPECIES_YORIHIME] = gMonIcon_Yorihime,
    [SPECIES_CKAGUYA] = gMonIcon_CKaguya,
    [SPECIES_KAGUYA] = gMonIcon_Kaguya,
    [SPECIES_CMOKOU] = gMonIcon_CMokou,
    [SPECIES_MOKOU] = gMonIcon_Mokou,
    [SPECIES_CHATATE] = gMonIcon_CHatate,
    [SPECIES_HATATE] = gMonIcon_Hatate,
    [SPECIES_CLETTY] = gMonIcon_CLetty,
    [SPECIES_LETTY] = gMonIcon_Letty,
    [SPECIES_CPATCHOULI] = gMonIcon_CPatchouli,
    [SPECIES_PATCHOULI] = gMonIcon_Patchouli,
    [SPECIES_CYUUGI] = gMonIcon_CYuugi,
    [SPECIES_YUUGI] = gMonIcon_Yuugi,
    [SPECIES_CTENSHI] = gMonIcon_CTenshi,
    [SPECIES_TENSHI] = gMonIcon_Tenshi,
    [SPECIES_CPARSEE] = gMonIcon_CParsee,
    [SPECIES_PARSEE] = gMonIcon_Parsee,
    [SPECIES_CMURASA] = gMonIcon_CMurasa,
    [SPECIES_MURASA] = gMonIcon_Murasa,
    [SPECIES_CKISUME] = gMonIcon_CKisume,
    [SPECIES_KISUME] = gMonIcon_Kisume,
    [SPECIES_CKOGASA] = gMonIcon_CKogasa,
    [SPECIES_KOGASA] = gMonIcon_Kogasa,
    [SPECIES_CSATORI] = gMonIcon_CSatori,
    [SPECIES_SATORI] = gMonIcon_Satori,
    [SPECIES_CEIRIN] = gMonIcon_CEirin,
    [SPECIES_EIRIN] = gMonIcon_Eirin,
    [SPECIES_CRAN] = gMonIcon_CRan,
    [SPECIES_RAN] = gMonIcon_Ran,
    [SPECIES_CDAIYOUSEI] = gMonIcon_CDaiyousei,
    [SPECIES_DAIYOUSEI] = gMonIcon_Daiyousei,
    [SPECIES_CNITORI] = gMonIcon_CNitori,
    [SPECIES_NITORI] = gMonIcon_Nitori,
    [SPECIES_CHINA] = gMonIcon_CHina,
    [SPECIES_HINA] = gMonIcon_Hina,
    [SPECIES_CKOMACHI] = gMonIcon_CKomachi,
    [SPECIES_KOMACHI] = gMonIcon_Komachi,
    [SPECIES_CYUYUKO] = gMonIcon_CYuyuko,
    [SPECIES_YUYUKO] = gMonIcon_Yuyuko,
    [SPECIES_CMEILING] = gMonIcon_CMeiling,
    [SPECIES_MEILING] = gMonIcon_Meiling,
    [SPECIES_CSAKUYA] = gMonIcon_CSakuya,
    [SPECIES_SAKUYA] = gMonIcon_Sakuya,
    [SPECIES_CLUNASA] = gMonIcon_CLunasa,
    [SPECIES_LUNASA] = gMonIcon_Lunasa,
    [SPECIES_CMERLIN] = gMonIcon_CMerlin,
    [SPECIES_MERLIN] = gMonIcon_Merlin,
    [SPECIES_CLYRICA] = gMonIcon_CLyrica,
    [SPECIES_LYRICA] = gMonIcon_Lyrica,
    [SPECIES_CLAYLA] = gMonIcon_CLayla,
    [SPECIES_LAYLA] = gMonIcon_Layla,
    [SPECIES_CKANAKO] = gMonIcon_CKanako,
    [SPECIES_KANAKO] = gMonIcon_Kanako,
    [SPECIES_CRIN] = gMonIcon_CRin,
    [SPECIES_RIN] = gMonIcon_Rin,
    [SPECIES_CUTSUHO] = gMonIcon_CUtsuho,
    [SPECIES_UTSUHO] = gMonIcon_Utsuho,
    [SPECIES_CICHIRIN] = gMonIcon_CIchirin,
    [SPECIES_ICHIRIN] = gMonIcon_Ichirin,
    [SPECIES_CSUNNYMILK] = gMonIcon_CSunnyMilk,
    [SPECIES_SUNNYMILK] = gMonIcon_SunnyMilk,
    [SPECIES_CLUNACHILD] = gMonIcon_CLunaChild,
    [SPECIES_LUNACHILD] = gMonIcon_LunaChild,
    [SPECIES_CSTARSAPPHIRE] = gMonIcon_CStarSapphire,
    [SPECIES_STARSAPPHIRE] = gMonIcon_StarSapphire,
    [SPECIES_CYUUKA] = gMonIcon_CYuuka,
    [SPECIES_YUUKA] = gMonIcon_Yuuka,
    [SPECIES_CAYA] = gMonIcon_CAya,
    [SPECIES_AYA] = gMonIcon_Aya,
    [SPECIES_CSHIKIEIKI] = gMonIcon_CShikieiki,
    [SPECIES_SHIKIEIKI] = gMonIcon_Shikieiki,
    [SPECIES_CSHOU] = gMonIcon_CShou,
    [SPECIES_SHOU] = gMonIcon_Shou,
    [SPECIES_CWRIGGLE] = gMonIcon_CWriggle,
    [SPECIES_WRIGGLE] = gMonIcon_Wriggle,
    [SPECIES_CTEWI] = gMonIcon_CTewi,
    [SPECIES_TEWI] = gMonIcon_Tewi,
    [SPECIES_KEDAMA] = gMonIcon_Kedama,
    [SPECIES_CNUE] = gMonIcon_CNue,
    [SPECIES_NUE] = gMonIcon_Nue,
    [SPECIES_CSUWAKO] = gMonIcon_CSuwako,
    [SPECIES_SUWAKO] = gMonIcon_Suwako,
    [SPECIES_REISENII] = gMonIcon_ReisenII,
    [SPECIES_CMARISA] = gMonIcon_CMarisa,
    [SPECIES_MARISA] = gMonIcon_Marisa,
    [SPECIES_CREIMU] = gMonIcon_CReimu,
    [SPECIES_REIMU] = gMonIcon_Reimu,
    [SPECIES_CBYAKUREN] = gMonIcon_CByakuren,
    [SPECIES_BYAKUREN] = gMonIcon_Byakuren,
    [SPECIES_KONNGARA] = gMonIcon_Konngara,
    [SPECIES_KIKURI] = gMonIcon_Kikuri,
    [SPECIES_YUUGENMAGAN] = gMonIcon_YuugenMagan,
    [SPECIES_CTOYOHIME] = gMonIcon_CToyohime,
    [SPECIES_TOYOHIME] = gMonIcon_Toyohime,
    [SPECIES_GOLIATH] = gMonIcon_Goliath,
    [SPECIES_SARIEL] = gMonIcon_Sariel,
    [SPECIES_AKYUU] = gMonIcon_Akyuu,
    [SPECIES_GENJII] = gMonIcon_Genjii,
    [SPECIES_TORI] = gMonIcon_Tori,
    [SPECIES_NAMAZU] = gMonIcon_Namazu,
    [SPECIES_CELLY] = gMonIcon_CElly,
    [SPECIES_ELLY] = gMonIcon_Elly,
    [SPECIES_CORANGE] = gMonIcon_COrange,
    [SPECIES_ORANGE] = gMonIcon_Orange,
    [SPECIES_YOUKI] = gMonIcon_Youki,
    [SPECIES_CCHIYURI] = gMonIcon_CChiyuri,
    [SPECIES_CHIYURI] = gMonIcon_Chiyuri,
    [SPECIES_CYUMEMI] = gMonIcon_CYumemi,
    [SPECIES_YUMEMI] = gMonIcon_Yumemi,
    [SPECIES_CELLEN] = gMonIcon_CEllen,
    [SPECIES_ELLEN] = gMonIcon_Ellen,
    [SPECIES_CKAZAMI] = gMonIcon_CKazami,
    [SPECIES_KAZAMI] = gMonIcon_Kazami,
    [SPECIES_CMEIRA] = gMonIcon_CMeira,
    [SPECIES_MEIRA] = gMonIcon_Meira,
    [SPECIES_CSARA] = gMonIcon_CSara,
    [SPECIES_SARA] = gMonIcon_Sara,
    [SPECIES_CLUIZE] = gMonIcon_CLuize,
    [SPECIES_LUIZE] = gMonIcon_Luize,
    [SPECIES_CMARGATROID] = gMonIcon_CMargatroid,
    [SPECIES_MARGATROID] = gMonIcon_Margatroid,
    [SPECIES_CKANA] = gMonIcon_CKana,
    [SPECIES_KANA] = gMonIcon_Kana,
    [SPECIES_CHAKUREI] = gMonIcon_CHakurei,
    [SPECIES_HAKUREI] = gMonIcon_Hakurei,
    [SPECIES_CKIRISAME] = gMonIcon_CKirisame,
    [SPECIES_KIRISAME] = gMonIcon_Kirisame,
    [SPECIES_CKOTOHIME] = gMonIcon_CKotohime,
    [SPECIES_KOTOHIME] = gMonIcon_Kotohime,
    [SPECIES_CYUMEKO] = gMonIcon_CYumeko,
    [SPECIES_YUMEKO] = gMonIcon_Yumeko,
    [SPECIES_CSHINKI] = gMonIcon_CShinki,
    [SPECIES_SHINKI] = gMonIcon_Shinki,
    [SPECIES_MIMICHAN] = gMonIcon_Mimichan,
    [SPECIES_RUUKOTO] = gMonIcon_Ruukoto,
    [SPECIES_CRIKA] = gMonIcon_CRika,
    [SPECIES_RIKA] = gMonIcon_Rika,
    [SPECIES_CMUGETSU] = gMonIcon_CMugetsu,
    [SPECIES_MUGETSU] = gMonIcon_Mugetsu,
    [SPECIES_CGENGETSU] = gMonIcon_CGengetsu,
    [SPECIES_GENGETSU] = gMonIcon_Gengetsu,
    [SPECIES_CKURUMI] = gMonIcon_CKurumi,
    [SPECIES_KURUMI] = gMonIcon_Kurumi,
    [SPECIES_CRIKAKO] = gMonIcon_CRikako,
    [SPECIES_RIKAKO] = gMonIcon_Rikako,
    [SPECIES_CYUKI] = gMonIcon_CYuki,
    [SPECIES_CMAI] = gMonIcon_CMai,
    [SPECIES_MAI] = gMonIcon_Mai,
    [SPECIES_DSUNNYMILK] = gMonIcon_DSunnyMilk,
    [SPECIES_TLUNACHILD] = gMonIcon_TLunaChild,
    [SPECIES_HSTARSAPPHIRE] = gMonIcon_HStarSapphire,
    [SPECIES_ANITORI] = gMonIcon_ANitori,
    [SPECIES_TNITORI] = gMonIcon_TNitori,
    [SPECIES_AMOKOU] = gMonIcon_AMokou,
    [SPECIES_DMOKOU] = gMonIcon_DMokou,
    [SPECIES_DREISEN] = gMonIcon_DReisen,
    [SPECIES_TREISEN] = gMonIcon_TReisen,
    [SPECIES_TSAKUYA] = gMonIcon_TSakuya,
    [SPECIES_HSAKUYA] = gMonIcon_HSakuya,
    [SPECIES_ARUMIA] = gMonIcon_ARumia,
    [SPECIES_SRUMIA] = gMonIcon_SRumia,
    [SPECIES_HMYSTIA] = gMonIcon_HMystia,
    [SPECIES_AMYSTIA] = gMonIcon_AMystia,
    [SPECIES_ACHEN] = gMonIcon_AChen,
    [SPECIES_TCHEN] = gMonIcon_TChen,
    [SPECIES_DYOUMU] = gMonIcon_DYoumu,
    [SPECIES_SYOUMU] = gMonIcon_SYoumu,
    [SPECIES_AYUUKA] = gMonIcon_AYuuka,
    [SPECIES_TYUUKA] = gMonIcon_TYuuka,
    [SPECIES_SAYA] = gMonIcon_SAya,
    [SPECIES_TAYA] = gMonIcon_TAya,
    [SPECIES_ATENSHI] = gMonIcon_ATenshi,
    [SPECIES_DTENSHI] = gMonIcon_DTenshi,
    [SPECIES_DPARSEE] = gMonIcon_DParsee,
    [SPECIES_TPARSEE] = gMonIcon_TParsee,
    [SPECIES_AKOISHI] = gMonIcon_AKoishi,
    [SPECIES_SKOISHI] = gMonIcon_SKoishi,
    [SPECIES_DBYAKUREN] = gMonIcon_DByakuren,
    [SPECIES_TBYAKUREN] = gMonIcon_TByakuren,
    [SPECIES_DICHIRIN] = gMonIcon_DIchirin,
    [SPECIES_TICHIRIN] = gMonIcon_TIchirin,
    [SPECIES_AKANAKO] = gMonIcon_AKanako,
    [SPECIES_DKANAKO] = gMonIcon_DKanako,
    [SPECIES_AKAGUYA] = gMonIcon_AKaguya,
    [SPECIES_DKAGUYA] = gMonIcon_DKaguya,
    [SPECIES_SHINGYOKUO] = gMonIcon_ShinGyokuO,
    [SPECIES_SHINGYOKUM] = gMonIcon_ShinGyokuM,
    [SPECIES_SHINGYOKUF] = gMonIcon_ShinGyokuF,
    [SPECIES_AUTSUHO] = gMonIcon_AUtsuho,
    [SPECIES_SUTSUHO] = gMonIcon_SUtsuho,
    [SPECIES_DMOMIJI] = gMonIcon_DMomiji,
    [SPECIES_ELIS] = gMonIcon_Elis,
    [SPECIES_MIMA] = gMonIcon_Mima,
    [SPECIES_SKOMACHI] = gMonIcon_SKomachi,
    [SPECIES_AKOMACHI] = gMonIcon_AKomachi,
    [SPECIES_AEIRIN] = gMonIcon_AEirin,
    [SPECIES_HEIRIN] = gMonIcon_HEirin,
    [SPECIES_DYUKARI] = gMonIcon_DYukari,
    [SPECIES_TYUKARI] = gMonIcon_TYukari,
    [SPECIES_AALICE] = gMonIcon_AAlice,
    [SPECIES_TALICE] = gMonIcon_TAlice,
    [SPECIES_AREIMU] = gMonIcon_AReimu,
    [SPECIES_DREIMU] = gMonIcon_DReimu,
    [SPECIES_SCIRNO] = gMonIcon_SCirno,
    [SPECIES_TCIRNO] = gMonIcon_TCirno,
    [SPECIES_DYUYUKO] = gMonIcon_DYuyuko,
    [SPECIES_AYUYUKO] = gMonIcon_AYuyuko,
    [SPECIES_HLUNASA] = gMonIcon_HLunasa,
    [SPECIES_HMERLIN] = gMonIcon_HMerlin,
    [SPECIES_HLYRICA] = gMonIcon_HLyrica,
    [SPECIES_ARAN] = gMonIcon_ARan,
    [SPECIES_HRAN] = gMonIcon_HRan,
    [SPECIES_AMEDICINE] = gMonIcon_AMedicine,
    [SPECIES_TMEDICINE] = gMonIcon_TMedicine,
    [SPECIES_AHINA] = gMonIcon_AHina,
    [SPECIES_DHINA] = gMonIcon_DHina,
    [SPECIES_SSHIZUHA] = gMonIcon_SShizuha,
    [SPECIES_SRIN] = gMonIcon_SRin,
    [SPECIES_ARIN] = gMonIcon_ARin,
    [SPECIES_ZOMBIEFAIRY] = gMonIcon_ZombieFairy,
    [SPECIES_HSHIZUHA] = gMonIcon_HShizuha,
    [SPECIES_ASUWAKO] = gMonIcon_ASuwako,
    [SPECIES_ASHOU] = gMonIcon_AShou,
    [SPECIES_TSHOU] = gMonIcon_TShou,
    [SPECIES_ATOKIKO] = gMonIcon_ATokiko,
    [SPECIES_DSUWAKO] = gMonIcon_DSuwako,
    [SPECIES_SYAMAME] = gMonIcon_SYamame,
    [SPECIES_SKOGASA] = gMonIcon_SKogasa,
    [SPECIES_TKOGASA] = gMonIcon_TKogasa,
    [SPECIES_DREMILIA] = gMonIcon_DRemilia,
    [SPECIES_SFLANDRE] = gMonIcon_SFlandre,
    [SPECIES_DWRIGGLE] = gMonIcon_DWriggle,
    [SPECIES_DMEILING] = gMonIcon_DMeiling,
    [SPECIES_TENSOKU] = gMonIcon_Tensoku,
    [SPECIES_ASUNNYMILK] = gMonIcon_ASunnyMilk,
    [SPECIES_ALUNACHILD] = gMonIcon_ALunaChild,
    [SPECIES_SWRIGGLE] = gMonIcon_SWriggle,
    [SPECIES_HKOAKUMA] = gMonIcon_HKoakuma,
    [SPECIES_SMEILING] = gMonIcon_SMeiling,
    [SPECIES_CELIS] = gMonIcon_CElis,
    [SPECIES_CSARIEL] = gMonIcon_CSariel,
    [SPECIES_ADMYSTIA] = gMonIcon_AdMystia,
    [SPECIES_THATATE] = gMonIcon_THatate,
    [SPECIES_DHATATE] = gMonIcon_DHatate,
    [SPECIES_AKISISTERS] = gMonIcon_AkiSisters,
    [SPECIES_DLAYLA] = gMonIcon_DLayla,
    [SPECIES_DKEINE] = gMonIcon_DKeine,
    [SPECIES_AREMILIA] = gMonIcon_ARemilia,
    [SPECIES_DTEWI] = gMonIcon_DTewi,
    [SPECIES_ATEWI] = gMonIcon_ATewi,
    [SPECIES_DSHIKIEIKI] = gMonIcon_DShikieiki,
    [SPECIES_DMINORIKO] = gMonIcon_DMinoriko,
    [SPECIES_TSUIKA] = gMonIcon_TSuika,
    [SPECIES_ASANAE] = gMonIcon_ASanae,
    [SPECIES_AFLANDRE] = gMonIcon_AFlandre,
    [SPECIES_ADAIYOUSEI] = gMonIcon_ADaiyousei,
    [SPECIES_ASHIKIEIKI] = gMonIcon_AShikieiki,
    [SPECIES_TTOYOHIME] = gMonIcon_TToyohime,
    [SPECIES_CKONNGARA] = gMonIcon_CKonngara,
    [SPECIES_CYUUGENMAGAN] = gMonIcon_CYuugenMagan,
    [SPECIES_ASUIKA] = gMonIcon_ASuika,
    [SPECIES_HLILYWHITE] = gMonIcon_HLilyWhite,
    [SPECIES_SLILYBLACK] = gMonIcon_SLilyBlack,
    [SPECIES_ANUE] = gMonIcon_ANue,
    [SPECIES_TNUE] = gMonIcon_TNue,
    [SPECIES_DPATCHOULI] = gMonIcon_DPatchouli,
    [SPECIES_DLETTY] = gMonIcon_DLetty,
    [SPECIES_HLETTY] = gMonIcon_HLetty,
    [SPECIES_SYORIHIME] = gMonIcon_SYorihime,
    [SPECIES_CSHINGYOKU] = gMonIcon_CShinGyoku,
    [SPECIES_ALILYBLACK] = gMonIcon_ALilyBlack,
    [SPECIES_DYUUGI] = gMonIcon_DYuugi,
    [SPECIES_TNAZRIN] = gMonIcon_TNazrin,
    [SPECIES_HNAZRIN] = gMonIcon_HNazrin,
    [SPECIES_TKISUME] = gMonIcon_TKisume,
    [SPECIES_AYUUGI] = gMonIcon_AYuugi,
    [SPECIES_HKEINE] = gMonIcon_HKeine,
    [SPECIES_DIKU] = gMonIcon_DIku,
    [SPECIES_TIKU] = gMonIcon_TIku,
    [SPECIES_AMINORIKO] = gMonIcon_AMinoriko,
    [SPECIES_RINNOSUKE] = gMonIcon_Rinnosuke,
    [SPECIES_ADCIRNO] = gMonIcon_AdCirno,
    [SPECIES_ADREISEN] = gMonIcon_AdReisen,
    [SPECIES_SSARIEL] = gMonIcon_SSariel,
    [SPECIES_ALILYWHITE] = gMonIcon_ALilyWhite,
    [SPECIES_CMIMA] = gMonIcon_CMima,
    [SPECIES_CKIKURI] = gMonIcon_CKikuri,
    [SPECIES_ADMEILING] = gMonIcon_AdMeiling,
    [SPECIES_APATCHOULI] = gMonIcon_APatchouli,
    [SPECIES_SMARISA] = gMonIcon_SMarisa,
    [SPECIES_AMARISA] = gMonIcon_AMarisa,
    [SPECIES_DMURASA] = gMonIcon_DMurasa,
    [SPECIES_AMURASA] = gMonIcon_AMurasa,
    [SPECIES_ASTARSAPPHIRE] = gMonIcon_AStarSapphire,
    [SPECIES_AKAZAMI] = gMonIcon_AKazami,
    [SPECIES_SMEDICINE] = gMonIcon_SMedicine,
    [SPECIES_DDAIYOUSEI] = gMonIcon_DDaiyousei,
    [SPECIES_TYAMAME] = gMonIcon_TYamame,
    [SPECIES_TSATORI] = gMonIcon_TSatori,
    [SPECIES_DSATORI] = gMonIcon_DSatori,
    [SPECIES_ADLETTY] = gMonIcon_AdLetty,
    [SPECIES_ADTEWI] = gMonIcon_AdTewi,
    [SPECIES_ADMARISA] = gMonIcon_AdMarisa,
    [SPECIES_ADALICE] = gMonIcon_AdAlice,
    [SPECIES_TSANAE] = gMonIcon_TSanae,
    [SPECIES_YUKI] = gMonIcon_Yuki,
    [SPECIES_ADMOKOU] = gMonIcon_AdMokou,
    [SPECIES_ADYUKARI] = gMonIcon_AdYukari,
    [SPECIES_ADRAN] = gMonIcon_AdRan,
    [SPECIES_ADCHEN] = gMonIcon_AdChen,
    [SPECIES_DARKALICE] = gMonIcon_DarkAlice,
    [SPECIES_TENMA] = gMonIcon_Tenma,
    [SPECIES_SENDAI] = gMonIcon_Sendai,
    [SPECIES_CKYOUKO] = gMonIcon_CKyouko,
    [SPECIES_KYOUKO] = gMonIcon_Kyouko,
    [SPECIES_CYOSHIKA] = gMonIcon_CYoshika,
    [SPECIES_YOSHIKA] = gMonIcon_Yoshika,
    [SPECIES_CSEIGA] = gMonIcon_CSeiga,
    [SPECIES_SEIGA] = gMonIcon_Seiga,
    [SPECIES_CTOJIKO] = gMonIcon_CTojiko,
    [SPECIES_TOJIKO] = gMonIcon_Tojiko,
    [SPECIES_CFUTO] = gMonIcon_CFuto,
    [SPECIES_FUTO] = gMonIcon_Futo,
    [SPECIES_CMIKO] = gMonIcon_CMiko,
    [SPECIES_MIKO] = gMonIcon_Miko,
    [SPECIES_CMAMIZOU] = gMonIcon_CMamizou,
    [SPECIES_MAMIZOU] = gMonIcon_Mamizou,
    [SPECIES_CKASEN] = gMonIcon_CKasen,
    [SPECIES_KASEN] = gMonIcon_Kasen,
    [SPECIES_GOMASEKI] = gMonIcon_Gomaseki,
    [SPECIES_CWAKASAGI] = gMonIcon_CWakasagi,
    [SPECIES_EGG] = gMonIcon_Egg,
};

const u8 gMonIconPaletteIndices[] =
{
    [SPECIES_NONE] = 0,
    [SPECIES_CSANAE] = 1,
    [SPECIES_SANAE] = 1,
    [SPECIES_CALICE] = 1,
    [SPECIES_ALICE] = 0,
    [SPECIES_CREISEN] = 0,
    [SPECIES_REISEN] = 0,
    [SPECIES_CLILYWHITE] = 0,
    [SPECIES_LILYWHITE] = 2,
    [SPECIES_CLILYBLACK] = 2,
    [SPECIES_LILYBLACK] = 1,
    [SPECIES_CMOMIJI] = 1,
    [SPECIES_MOMIJI] = 0,
    [SPECIES_CSHIZUHA] = 1,
    [SPECIES_SHIZUHA] = 2,
    [SPECIES_CMEDICINE] = 2,
    [SPECIES_MEDICINE] = 0,
    [SPECIES_CKOAKUMA] = 0,
    [SPECIES_KOAKUMA] = 0,
    [SPECIES_CNAZRIN] = 2,
    [SPECIES_NAZRIN] = 1,
    [SPECIES_CTOKIKO] = 0,
    [SPECIES_TOKIKO] = 0,
    [SPECIES_CREMILIA] = 2,
    [SPECIES_REMILIA] = 2,
    [SPECIES_CCIRNO] = 2,
    [SPECIES_CIRNO] = 0,
    [SPECIES_CRUMIA] = 2,
    [SPECIES_RUMIA] = 2,
    [SPECIES_SHANGHAI] = 2,
    [SPECIES_CFLANDRE] = 2,
    [SPECIES_FLANDRE] = 2,
    [SPECIES_HOURAI] = 2,
    [SPECIES_CYOUMU] = 2,
    [SPECIES_YOUMU] = 2,
    [SPECIES_CYUKARI] = 0,
    [SPECIES_YUKARI] = 0,
    [SPECIES_CSUIKA] = 2,
    [SPECIES_SUIKA] = 1,
    [SPECIES_CMYSTIA] = 0,
    [SPECIES_MYSTIA] = 0,
    [SPECIES_CMINORIKO] = 2,
    [SPECIES_MINORIKO] = 2,
    [SPECIES_CKEINE] = 1,
    [SPECIES_KEINE] = 0,
    [SPECIES_AKEINE] = 0,
    [SPECIES_CIKU] = 0,
    [SPECIES_IKU] = 0,
    [SPECIES_CKOISHI] = 0,
    [SPECIES_KOISHI] = 2,
    [SPECIES_CYAMAME] = 2,
    [SPECIES_YAMAME] = 2,
    [SPECIES_CCHEN] = 1,
    [SPECIES_CHEN] = 1,
    [SPECIES_CYORIHIME] = 1,
    [SPECIES_YORIHIME] = 2,
    [SPECIES_CKAGUYA] = 1,
    [SPECIES_KAGUYA] = 2,
    [SPECIES_CMOKOU] = 0,
    [SPECIES_MOKOU] = 0,
    [SPECIES_CHATATE] = 0,
    [SPECIES_HATATE] = 0,
    [SPECIES_CLETTY] = 0,
    [SPECIES_LETTY] = 2,
    [SPECIES_CPATCHOULI] = 2,
    [SPECIES_PATCHOULI] = 2,
    [SPECIES_CYUUGI] = 0,
    [SPECIES_YUUGI] = 2,
    [SPECIES_CTENSHI] = 0,
    [SPECIES_TENSHI] = 1,
    [SPECIES_CPARSEE] = 1,
    [SPECIES_PARSEE] = 1,
    [SPECIES_CMURASA] = 2,
    [SPECIES_MURASA] = 2,
    [SPECIES_CKISUME] = 1,
    [SPECIES_KISUME] = 1,
    [SPECIES_CKOGASA] = 1,
    [SPECIES_KOGASA] = 0,
    [SPECIES_CSATORI] = 0,
    [SPECIES_SATORI] = 0,
    [SPECIES_CEIRIN] = 0,
    [SPECIES_EIRIN] = 0,
    [SPECIES_CRAN] = 0,
    [SPECIES_RAN] = 1,
    [SPECIES_CDAIYOUSEI] = 2,
    [SPECIES_DAIYOUSEI] = 2,
    [SPECIES_CNITORI] = 2,
    [SPECIES_NITORI] = 2,
    [SPECIES_CHINA] = 2,
    [SPECIES_HINA] = 2,
    [SPECIES_CKOMACHI] = 2,
    [SPECIES_KOMACHI] = 2,
    [SPECIES_CYUYUKO] = 2,
    [SPECIES_YUYUKO] = 2,
    [SPECIES_CMEILING] = 2,
    [SPECIES_MEILING] = 2,
    [SPECIES_CSAKUYA] = 2,
    [SPECIES_SAKUYA] = 1,
    [SPECIES_CLUNASA] = 2,
    [SPECIES_LUNASA] = 2,
    [SPECIES_CMERLIN] = 0,
    [SPECIES_MERLIN] = 0,
    [SPECIES_CLYRICA] = 0,
    [SPECIES_LYRICA] = 1,
    [SPECIES_CLAYLA] = 1,
    [SPECIES_LAYLA] = 1,
    [SPECIES_CKANAKO] = 2,
    [SPECIES_KANAKO] = 2,
    [SPECIES_CRIN] = 1,
    [SPECIES_RIN] = 2,
    [SPECIES_CUTSUHO] = 2,
    [SPECIES_UTSUHO] = 1,
    [SPECIES_CICHIRIN] = 1,
    [SPECIES_ICHIRIN] = 0,
    [SPECIES_CSUNNYMILK] = 0,
    [SPECIES_SUNNYMILK] = 1,
    [SPECIES_CLUNACHILD] = 0,
    [SPECIES_LUNACHILD] = 0,
    [SPECIES_CSTARSAPPHIRE] = 0,
    [SPECIES_STARSAPPHIRE] = 0,
    [SPECIES_CYUUKA] = 2,
    [SPECIES_YUUKA] = 2,
    [SPECIES_CAYA] = 0,
    [SPECIES_AYA] = 1,
    [SPECIES_CSHIKIEIKI] = 2,
    [SPECIES_SHIKIEIKI] = 1,
    [SPECIES_CSHOU] = 0,
    [SPECIES_SHOU] = 2,
    [SPECIES_CWRIGGLE] = 2,
    [SPECIES_WRIGGLE] = 0,
    [SPECIES_CTEWI] = 0,
    [SPECIES_TEWI] = 2,
    [SPECIES_KEDAMA] = 2,
    [SPECIES_CNUE] = 2,
    [SPECIES_NUE] = 0,
    [SPECIES_CSUWAKO] = 0,
    [SPECIES_SUWAKO] = 0,
    [SPECIES_REISENII] = 0,
    [SPECIES_CMARISA] = 0,
    [SPECIES_MARISA] = 0,
    [SPECIES_CREIMU] = 2,
    [SPECIES_REIMU] = 2,
    [SPECIES_CBYAKUREN] = 0,
    [SPECIES_BYAKUREN] = 1,
    [SPECIES_KONNGARA] = 0,
    [SPECIES_KIKURI] = 0,
    [SPECIES_YUUGENMAGAN] = 0,
    [SPECIES_CTOYOHIME] = 0,
    [SPECIES_TOYOHIME] = 0,
    [SPECIES_GOLIATH] = 2,
    [SPECIES_SARIEL] = 2,
    [SPECIES_AKYUU] = 0,
    [SPECIES_GENJII] = 1,
    [SPECIES_TORI] = 1,
    [SPECIES_NAMAZU] = 1,
    [SPECIES_CELLY] = 1,
    [SPECIES_ELLY] = 1,
    [SPECIES_CORANGE] = 1,
    [SPECIES_ORANGE] = 2,
    [SPECIES_YOUKI] = 2,
    [SPECIES_CCHIYURI] = 2,
    [SPECIES_CHIYURI] = 2,
    [SPECIES_CYUMEMI] = 2,
    [SPECIES_YUMEMI] = 2,
    [SPECIES_CELLEN] = 2,
    [SPECIES_ELLEN] = 0,
    [SPECIES_CKAZAMI] = 0,
    [SPECIES_KAZAMI] = 1,
    [SPECIES_CMEIRA] = 0,
    [SPECIES_MEIRA] = 2,
    [SPECIES_CSARA] = 2,
    [SPECIES_SARA] = 0,
    [SPECIES_CLUIZE] = 0,
    [SPECIES_LUIZE] = 0,
    [SPECIES_CMARGATROID] = 1,
    [SPECIES_MARGATROID] = 2,
    [SPECIES_CKANA] = 2,
    [SPECIES_KANA] = 0,
    [SPECIES_CHAKUREI] = 0,
    [SPECIES_HAKUREI] = 2,
    [SPECIES_CKIRISAME] = 0,
    [SPECIES_KIRISAME] = 0,
    [SPECIES_CKOTOHIME] = 1,
    [SPECIES_KOTOHIME] = 2,
    [SPECIES_CYUMEKO] = 2,
    [SPECIES_YUMEKO] = 1,
    [SPECIES_CSHINKI] = 1,
    [SPECIES_SHINKI] = 1,
    [SPECIES_MIMICHAN] = 1,
    [SPECIES_RUUKOTO] = 2,
    [SPECIES_CRIKA] = 2,
    [SPECIES_RIKA] = 1,
    [SPECIES_CMUGETSU] = 1,
    [SPECIES_MUGETSU] = 1,
    [SPECIES_CGENGETSU] = 0,
    [SPECIES_GENGETSU] = 0,
    [SPECIES_CKURUMI] = 2,
    [SPECIES_KURUMI] = 2,
    [SPECIES_CRIKAKO] = 2,
    [SPECIES_RIKAKO] = 0,
    [SPECIES_CYUKI] = 0,
    [SPECIES_CMAI] = 0,
    [SPECIES_MAI] = 1,
    [SPECIES_DSUNNYMILK] = 0,
    [SPECIES_TLUNACHILD] = 2,
    [SPECIES_HSTARSAPPHIRE] = 2,
    [SPECIES_ANITORI] = 2,
    [SPECIES_TNITORI] = 0,
    [SPECIES_AMOKOU] = 0,
    [SPECIES_DMOKOU] = 2,
    [SPECIES_DREISEN] = 0,
    [SPECIES_TREISEN] = 0,
    [SPECIES_TSAKUYA] = 1,
    [SPECIES_HSAKUYA] = 2,
    [SPECIES_ARUMIA] = 0,
    [SPECIES_SRUMIA] = 0,
    [SPECIES_HMYSTIA] = 2,
    [SPECIES_AMYSTIA] = 0,
    [SPECIES_ACHEN] = 0,
    [SPECIES_TCHEN] = 2,
    [SPECIES_DYOUMU] = 2,
    [SPECIES_SYOUMU] = 0,
    [SPECIES_AYUUKA] = 0,
    [SPECIES_TYUUKA] = 0,
    [SPECIES_SAYA] = 0,
    [SPECIES_TAYA] = 2,
    [SPECIES_ATENSHI] = 0,
    [SPECIES_DTENSHI] = 0,
    [SPECIES_DPARSEE] = 0,
    [SPECIES_TPARSEE] = 0,
    [SPECIES_AKOISHI] = 0,
    [SPECIES_SKOISHI] = 0,
    [SPECIES_DBYAKUREN] = 0,
    [SPECIES_TBYAKUREN] = 2,
    [SPECIES_DICHIRIN] = 1,
    [SPECIES_TICHIRIN] = 2,
    [SPECIES_AKANAKO] = 2,
    [SPECIES_DKANAKO] = 1,
    [SPECIES_AKAGUYA] = 1,
    [SPECIES_DKAGUYA] = 1,
    [SPECIES_SHINGYOKUO] = 1,
    [SPECIES_SHINGYOKUM] = 1,
    [SPECIES_SHINGYOKUF] = 0,
    [SPECIES_AUTSUHO] = 2,
    [SPECIES_SUTSUHO] = 0,
    [SPECIES_DMOMIJI] = 1,
    [SPECIES_ELIS] = 0,
    [SPECIES_MIMA] = 1,
    [SPECIES_SKOMACHI] = 0,
    [SPECIES_AKOMACHI] = 1,
    [SPECIES_AEIRIN] = 1,
    [SPECIES_HEIRIN] = 1,
    [SPECIES_DYUKARI] = 0,
    [SPECIES_TYUKARI] = 1,
    [SPECIES_AALICE] = 0,
    [SPECIES_TALICE] = 0,
    [SPECIES_AREIMU] = 0,
    [SPECIES_DREIMU] = 0,
    [SPECIES_SCIRNO] = 0,
    [SPECIES_TCIRNO] = 0,
    [SPECIES_DYUYUKO] = 2,
    [SPECIES_AYUYUKO] = 2,
    [SPECIES_HLUNASA] = 2,
    [SPECIES_HMERLIN] = 2,
    [SPECIES_HLYRICA] = 0,
    [SPECIES_ARAN] = 2,
    [SPECIES_HRAN] = 0,
    [SPECIES_AMEDICINE] = 2,
    [SPECIES_TMEDICINE] = 1,
    [SPECIES_AHINA] = 1,
    [SPECIES_DHINA] = 1,
    [SPECIES_SSHIZUHA] = 1,
    [SPECIES_SRIN] = 1,
    [SPECIES_ARIN] = 1,
    [SPECIES_ZOMBIEFAIRY] = 0,
    [SPECIES_HSHIZUHA] = 1,
    [SPECIES_ASUWAKO] = 1,
    [SPECIES_ASHOU] = 1,
    [SPECIES_TSHOU] = 2,
    [SPECIES_ATOKIKO] = 2,
    [SPECIES_DSUWAKO] = 1,
    [SPECIES_SYAMAME] = 1,
    [SPECIES_SKOGASA] = 1,
    [SPECIES_TKOGASA] = 0,
    [SPECIES_DREMILIA] = 0,
    [SPECIES_SFLANDRE] = 2,
    [SPECIES_DWRIGGLE] = 0,
    [SPECIES_DMEILING] = 2,
    [SPECIES_TENSOKU] = 0,
    [SPECIES_ASUNNYMILK] = 0,
    [SPECIES_ALUNACHILD] = 2,
    [SPECIES_SWRIGGLE] = 1,
    [SPECIES_HKOAKUMA] = 1,
    [SPECIES_SMEILING] = 0,
    [SPECIES_CELIS] = 0,
    [SPECIES_CSARIEL] = 1,
    [SPECIES_ADMYSTIA] = 2,
    [SPECIES_THATATE] = 0,
    [SPECIES_DHATATE] = 0,
    [SPECIES_AKISISTERS] = 0,
    [SPECIES_DLAYLA] = 0,
    [SPECIES_DKEINE] = 0,
    [SPECIES_AREMILIA] = 2,
    [SPECIES_DTEWI] = 0,
    [SPECIES_ATEWI] = 0,
    [SPECIES_DSHIKIEIKI] = 0,
    [SPECIES_DMINORIKO] = 1,
    [SPECIES_TSUIKA] = 1,
    [SPECIES_ASANAE] = 1,
    [SPECIES_AFLANDRE] = 2,
    [SPECIES_ADAIYOUSEI] = 1,
    [SPECIES_ASHIKIEIKI] = 1,
    [SPECIES_TTOYOHIME] = 0,
    [SPECIES_CKONNGARA] = 1,
    [SPECIES_CYUUGENMAGAN] = 0,
    [SPECIES_ASUIKA] = 2,
    [SPECIES_HLILYWHITE] = 2,
    [SPECIES_SLILYBLACK] = 0,
    [SPECIES_ANUE] = 1,
    [SPECIES_TNUE] = 1,
    [SPECIES_DPATCHOULI] = 2,
    [SPECIES_DLETTY] = 0,
    [SPECIES_HLETTY] = 1,
    [SPECIES_SYORIHIME] = 0,
    [SPECIES_CSHINGYOKU] = 2,
    [SPECIES_ALILYBLACK] = 0,
    [SPECIES_DYUUGI] = 2,
    [SPECIES_TNAZRIN] = 0,
    [SPECIES_HNAZRIN] = 0,
    [SPECIES_TKISUME] = 2,
    [SPECIES_AYUUGI] = 0,
    [SPECIES_HKEINE] = 0,
    [SPECIES_DIKU] = 0,
    [SPECIES_TIKU] = 0,
    [SPECIES_AMINORIKO] = 0,
    [SPECIES_RINNOSUKE] = 0,
    [SPECIES_ADCIRNO] = 0,
    [SPECIES_ADREISEN] = 0,
    [SPECIES_SSARIEL] = 2,
    [SPECIES_ALILYWHITE] = 2,
    [SPECIES_CMIMA] = 1,
    [SPECIES_CKIKURI] = 1,
    [SPECIES_ADMEILING] = 2,
    [SPECIES_APATCHOULI] = 1,
    [SPECIES_SMARISA] = 0,
    [SPECIES_AMARISA] = 2,
    [SPECIES_DMURASA] = 2,
    [SPECIES_AMURASA] = 0,
    [SPECIES_ASTARSAPPHIRE] = 0,
    [SPECIES_AKAZAMI] = 0,
    [SPECIES_SMEDICINE] = 0,
    [SPECIES_DDAIYOUSEI] = 0,
    [SPECIES_TYAMAME] = 0,
    [SPECIES_TSATORI] = 2,
    [SPECIES_DSATORI] = 0,
    [SPECIES_ADLETTY] = 1,
    [SPECIES_ADTEWI] = 2,
    [SPECIES_ADMARISA] = 2,
    [SPECIES_ADALICE] = 2,
    [SPECIES_TSANAE] = 0,
    [SPECIES_YUKI] = 0,
    [SPECIES_ADMOKOU] = 2,
    [SPECIES_ADYUKARI] = 2,
    [SPECIES_ADRAN] = 0,
    [SPECIES_ADCHEN] = 0,
    [SPECIES_DARKALICE] = 0,
    [SPECIES_TENMA] = 1,
    [SPECIES_SENDAI] = 1,
    [SPECIES_CKYOUKO] = 1,
    [SPECIES_KYOUKO] = 2,
    [SPECIES_CYOSHIKA] = 2,
    [SPECIES_YOSHIKA] = 0,
    [SPECIES_CSEIGA] = 0,
    [SPECIES_SEIGA] = 0,
    [SPECIES_CTOJIKO] = 0,
    [SPECIES_TOJIKO] = 2,
    [SPECIES_CFUTO] = 2,
    [SPECIES_FUTO] = 2,
    [SPECIES_CMIKO] = 2,
    [SPECIES_MIKO] = 0,
    [SPECIES_CMAMIZOU] = 1,
    [SPECIES_MAMIZOU] = 0,
    [SPECIES_CKASEN] = 2,
    [SPECIES_KASEN] = 0,
    [SPECIES_GOMASEKI] = 0,
    [SPECIES_CWAKASAGI] = 0,
    [SPECIES_EGG] = 1,
};

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },

// There are only 3 actual palettes. The following are unused
// and don't point to valid data.
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 handleGomaseki)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality, handleGomaseki),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 handleGomaseki)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    iconTemplate.image = GetMonIconTiles(species, handleGomaseki);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;
    if (species > NUM_SPECIES)
        result = INVALID_ICON_SPECIES;
    else
        result = species;
    return result;
}

u16 GetIconSpeciesNoPersonality(u16 species)
{
    u16 value;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return GetIconSpecies(species, 0);
}

const u8 *GetMonIconPtr(u16 species, u32 personality, bool32 handleGomaseki)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), handleGomaseki);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8 *GetMonIconTiles(u16 species, bool32 handleGomaseki)
{
    const u8 *iconSprite = gMonIconTable[species];
    if (species == SPECIES_GOMASEKI && handleGomaseki == TRUE)
    {
        iconSprite = (const u8 *)(0x400 + (u32)iconSprite); // use the specific Gomaseki form icon (Speed in this case)
    }
    return iconSprite;
}

void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    if (offset <= BG_PLTT_ID(16 - ARRAY_COUNT(gMonIconPaletteTable)))
    {
        for (i = 0; i < (int)ARRAY_COUNT(gMonIconPaletteTable); i++)
        {
            LoadPalette(gMonIconPaletteTable[i].data, offset, PLTT_SIZE_4BPP);
            offset += 16;
        }
    }
}

u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteIndices[species];
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gMonIconPaletteIndices[species];
}

const u16 *GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
