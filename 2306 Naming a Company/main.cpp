#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// class Solution
// {
//     const int ALHPABET_SIZE = 26;

// public:
//     // long long distinctNames(vector<string> &ideas)
//     // {
//     //     long long count = 0;
//     //     unordered_map<string, pair<vector<int>, int>> suffix_hash_table;

//     //     for (auto name : ideas)
//     //     {
//     //         string suffix(name.begin() + 1, name.end());

//     //         if (!suffix_hash_table.count(suffix))
//     //             suffix_hash_table[suffix] = {vector<int>(ALHPABET_SIZE, 0), 0};

//     //         suffix_hash_table[suffix].first[name[0] - 'a'] += 1;
//     //         suffix_hash_table[suffix].second += 1;
//     //     }

//     //     // for (auto [key, value] : suffix_hash_table)
//     //     // {
//     //     //     cout << key << " " << value.second << " | ";
//     //     //     for (int i = 0; i < value.first.size(); ++i)
//     //     //     {
//     //     //         if (value.first[i] != 0)
//     //     //             cout << "{" << char('a' + i) << ", " << value.first[i] << "} ";
//     //     //     }
//     //     //     cout << endl;
//     //     // }
//     //     // cout << endl;

//     //     for (auto iter1 = suffix_hash_table.begin(); iter1 != suffix_hash_table.end(); ++iter1)
//     //     {
//     //         auto [idea1, first_letters_count1] = *iter1;

//     //         for (auto iter2 = iter1; iter2 != suffix_hash_table.end(); ++iter2)
//     //         {
//     //             auto [idea2, first_letters_count2] = *iter2;

//     //             if (idea1 == idea2)
//     //                 continue;

//     //             int distinct_1 = first_letters_count1.second;
//     //             int distinct_2 = first_letters_count2.second;

//     //             for (int i = 0; i < first_letters_count1.first.size(); ++i)
//     //             {
//     //                 if (first_letters_count1.first[i] && first_letters_count2.first[i])
//     //                 {
//     //                     distinct_1 -= first_letters_count1.first[i];
//     //                     distinct_2 -= first_letters_count2.first[i];
//     //                 }
//     //             }
//     //             count += 2 * distinct_1 * distinct_2;
//     //         }
//     //     }
//     //     // for (auto [idea1, first_letters_count1] : suffix_hash_table)
//     //     // {
//     //     //     for (auto [idea2, first_letters_count2] : suffix_hash_table)
//     //     //     {
//     //     //         if (idea1 == idea2)
//     //     //             continue;

//     //     //         for (int i = 0; i < first_letters_count1.first.size(); ++i)
//     //     //         {
//     //     //             int delta = first_letters_count1.first[i] * (first_letters_count2.second - first_letters_count2.first[i]);
//     //     //             if (first_lett ers_count1.first[i])
//     //     //                 cout << idea1 << " " << idea2 << " | " << char('a' + i) << " " << first_letters_count1.first[i] << " " << first_letters_count2.first[i] << " " << delta << endl;
//     //     //             count += delta;
//     //     //         }
//     //     //     }
//     //     // }

//     //     return count;
//     // }

//     long long distinctNames(vector<string> &ideas)
//     {
//         long long count = 0;
//         vector<int> first_letters_count(ALHPABET_SIZE, 0);
//         unordered_set<string> unique_ideas;
//         unordered_map<string, pair<vector<int>, int>> suffix_hash_table;

//         for (auto name : ideas)
//         {
//             unique_ideas.insert(name);
//         }

//         for (auto name : unique_ideas)
//         {
//             string suffix(name.begin() + 1, name.end());
//             first_letters_count[name[0] - 'a'] += 1;

//             if (!suffix_hash_table.count(suffix))
//                 suffix_hash_table[suffix] = {vector<int>(ALHPABET_SIZE, 0), 0};

//             suffix_hash_table[suffix].first[name[0] - 'a'] += 1;
//             suffix_hash_table[suffix].second += 1;
//         }

//         for (auto [suffix, suffix_letters] : suffix_hash_table)
//         {
//             int distinct_1 = suffix_letters.second;

//             // cout << suffix << endl;
//             int new_words_count = 0;
//             int count_count = 0;
//             for (int i = 0; i < first_letters_count.size(); ++i)
//             {
//                 if (first_letters_count[i] && !suffix_letters.first[i])
//                 {
//                     new_words_count += first_letters_count[i];
//                     // cout << char('a' + i) << " " << distinct_1 << " " << new_pairs_count << endl;
//                 }
//             }
//             count += new_words_count;
//         }

//         return count;
//     }
// };

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for (auto &idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));

        // Calculate number of valid names from every pair of groups.
        long long answer = 0;
        for (int i = 0; i < 25; ++i)
        {
            for (int j = i + 1; j < 26; ++j)
            {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for (auto &ideaA : initialGroup[i])
                {
                    if (initialGroup[j].count(ideaA))
                    {
                        numOfMutual++;
                    }
                }

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
};

int main()
{
    Solution my_sol;
    vector<string> ideas({"coffee", "donuts", "time", "toffee"});
    // vector<string> ideas({"lack", "back"});
    // vector<string> ideas({"aaa", "baa", "caa", "bbb", "cbb", "dbb"});
    // vector<string> ideas({"alrgtxxdj", "illqfngl", "rlrgtxxdj"});
    // vector<string> ideas({"ax", "iy", "rx"});
    // vector<string> ideas({"sxozvlh",
    //                       "wcippkmzbn",
    //                       "c", "pcclylt", "gnx", "kbjdsedgyl", "bazn", "khafr", "g", "djmoyyaq", "dbjqsc", "gym", "vvhdrsdn", "uyoxkipbk", "gskzakfcya", "qovlnttgm", "hazofenuaj", "gqgo", "jt", "mnykuknekp", "z", "dgeueigih", "lwedeysrot", "juixndwn", "cvab", "m", "rc", "jfgu", "gq", "zdsw", "hibonudax", "mybeatsxk", "gcjkn", "oipqle", "ycl", "p", "heb", "jelx", "f", "utctbpln", "doli", "gkrairj", "wigqavei", "oorznuol", "ahtwawr", "unfis", "fymusgpkyh", "jjocykhzd", "hqvc", "mf", "n", "yftze", "lw", "wbay", "hyecpye", "zkdjqdmd", "hxlyiidtqo", "spt", "w", "ugmleroj", "qrvn", "na", "mrvaxr", "r", "acym", "ctbubegn", "phr", "x", "qkjmovdw", "vvype", "jwfuhlyw", "ps", "pk", "gj", "krcpjd", "bsfjx", "hsxac", "jatbpwxt", "pm", "wzhbdx", "gtpcilzgf", "flixcgehg", "lgmdm", "mtdvtzety", "pktearar", "tnpuqp", "inuruwt", "gcmjeud", "nbjyda", "gaovdhhb", "af", "dqb", "bim", "qhiih", "b", "yvvfeg", "juypz", "mkravc", "kkxp", "rcdunwbhi", "jeetdkgjjq", "wngzcrbe", "nnqnyb", "bevoqvi", "fvxlty", "rpopifqye", "dtgc", "qdcl", "ubkrsukgl", "vi", "ycrosssc", "rjene", "jsy", "hbfh", "yxjhdxmufy", "nwfwfyfx", "unpfulzc", "ziuqkxhcl", "qkymvrei", "bbbklyd", "acbozi", "iikcqw", "xbpsyvt", "ybcktdp", "ewjadgo", "xzrbajrkqf", "qbgrwmiopx", "h", "fjcefg", "nw", "fshtfxwij", "iviftcaif", "rxidmzccd", "vdgqbnnno", "xpjyovzw", "pbfhcrqqm", "vvr", "k", "hlcwlaitdv", "ersaotypsj", "xxw", "oystungxzb", "pdixvb", "jdhv", "upm", "deisv", "xpgyro", "ssu", "qhfqbat", "has", "hrnmexwrx", "txaxyutw", "tjr", "tuezzgzu", "myaix", "rhwhezfxe", "avfdcyzvcs", "oxx", "qsyoidolv", "qeqybyg", "luedabbts", "ryifjy", "mrbn", "esyeqcqwe", "nkjysupkm", "ppqsm", "oxvno", "srvosth", "qqsezcc", "zzxyatudhw", "rteldzt", "ccqd", "wbhsrnju", "gxkaaeauh", "jbtsgmuo", "hgkftclc", "wl", "lozkn", "aslizsts", "yrwsnitw", "fxcsyp", "hmlylh", "pwsof", "y", "eomg", "j", "ts", "ommkytlgkb", "zri", "xidnnofxb", "kbacdpjf", "vijtxby", "bjeiks", "vpioxsqdr", "cm", "aa", "kpimtuqpgj", "txbuymfnxg", "qdgqbnnno", "my", "wpot", "lwqp", "tifw", "iucrm", "pogyhfhfe", "dcgoocnycp", "e", "iltoolwrt", "dfxu", "zpg", "cuhklmdvzs", "nq", "q", "s", "pwndto", "ibxui", "tfbunnyrzs", "wfyo", "vmf", "clzjq", "lhpsylmev", "dyajmdh", "jqxmegtqqk", "utrsgiuyzy", "ulsf", "xddkihux", "homg", "ueydaexi", "t", "juhr", "lzbz", "tfw", "d", "me", "owqpagtsli", "bujlzfzne", "fworelhg", "aqhxamy", "idlfar", "qw", "iajbsphq", "vjjuqleza", "iqfehffrfq", "igi", "xefqec", "iwinzgjzhm", "jewfigd", "hn", "bxjupoo", "gkavmn", "xahpbdahc", "xsawfjxpu", "trajekzef", "mvmpajhq", "zb", "rmsk", "pqzkm", "mb", "lrnx", "uhnnazu", "igtqtic", "gijtxby", "zxvou", "wmj", "cbhmcukf", "ppooh", "nhmiuk", "iqjzlp", "zztanfh", "cycv", "jthl", "eoxrcv", "dcfuzgxob", "jqcnkc", "tinzpokiyq", "wk", "ggyuhxvieq", "cjxymjusoq", "oakuehxpoq", "dlititodh", "ha", "nzweogclz", "yurjyjiu", "qeoagmtgpd", "kzi", "pel", "eefsahbhx", "druzhqkt", "mgkm", "ksctlm", "kgvszrw", "jwzfxx", "kxn", "trnpjwtbzf", "bclwmat", "ukaqsvnto", "jgujkc", "hacuxargvk", "ybvkdvh", "zjxxm", "gpgdu", "apzufliqih", "fqt", "hfb", "if", "jsmqvth", "sovb", "nmq", "hxxeotguk", "sezrqqsge", "italmg", "wp", "rfjy", "bbxx", "rp", "fibjh", "ihisumiu", "umtbiu", "cccs", "hznvjyt", "mpryxcq", "idxuwkld", "rtfban", "not", "jykdw", "fhcakewibq", "aqirjfmrjh", "wmdldaqma", "ocwnhhtz", "iluth", "wooptypz", "mu", "tget", "ezhdqspeq", "ubdwpgxus", "kovtaamr", "envdznui", "vlcwlaitdv", "cazouhopch", "ebiwnzyxk", "mygkjreov", "gmwssjfoyt", "uhkj", "yfoeybd", "tgkulwfxm", "kxpdgchr", "yjddhbi", "glddpyxug", "u", "axaxyutw", "hxecznzozq", "lfovcrc", "rbkbbmjm", "ykuhick", "kdtvizr", "fgpnvgtkd", "iw", "mutnnxvdcf", "oeoicet", "qqjzaxyfq", "kmfhxraeu", "kjjpjaymi", "jlcwlaitdv", "swjqmuymcb", "fwaaekf", "mbpi", "ywia", "sugmzgx", "du", "zedg", "iprtgiqqlc", "aamgzwnq", "boot", "fzvhqg", "tffwyjrnol", "aeyiflxov", "auil", "khb", "ihuvq", "dshtfxwij", "bxmfmtx", "nabjw", "ouztdduhrv", "zrv", "wqvsecesjd", "ewsus", "mtkq", "fax", "jhvfyvdvnw", "uvrcm", "rxpub", "qo", "cookius", "qnxcrga", "qqetoiuch", "wntqscbrl", "mkdkpzpdhk", "vdgk", "zucidbg", "lszovvad", "wvi", "ioeyiovve", "lkht", "zecoxkni", "ysqm", "phemyw", "earydq", "nz", "hizgnxqa", "uw", "uacs", "naqierbwsi", "sxbzcfak", "azcqxek", "uxnw", "fqeqm", "btxxz", "onbgiiat", "ifrxqmq", "vqy", "aweu", "ihkk", "gtiic", "mkzbtijoqu", "ydwb", "elmufzn", "jlelpab", "bhxv", "lr", "zerc", "gqm", "kxstf", "awyut", "rocaffz", "utl", "nhwuwhv", "o", "ogjjcyl", "tepq", "ml", "gdtojjh", "oc", "ef", "cneujvkvuw", "bti", "oclwmat", "ynrwrjpok", "jmtad", "embqacqgl", "plokoz", "fmxxn", "sdfnsbdkjv", "xwn", "fautnhoc", "zzjgf", "qfu", "dowqh", "ukhuceb", "blv", "jhooqvy", "hgcx", "umcihvsxb", "tuisrd", "qshmacvg", "jmygyysr", "fa", "fnwpy", "jqmomluklc", "jwmf", "xpnufzzogc", "fe", "fmhbaxz", "pfjka", "dnwyh", "vw", "ugggelhce", "gbiijfe", "gtbjl", "ndics", "in", "jog", "ege", "vb", "l", "ueyteuv", "efvbusuh", "ohpwel", "jifehzsgv", "qrtbrdbjbe", "geetdkgjjq", "yuhzrystlr", "uggxyf", "cxzhrjkekr", "rxhvpm", "psxww", "dya", "kffgfpvss", "mjnohrgw", "xrmmeo", "wgzgn", "ztbh", "gugtdsyb", "fxjzkyivh", "riaiefagi", "mwayh", "gzll", "ctvze", "shiu", "haojlyzdpu", "dvytr", "mwjvzc", "usxuymemu", "hl", "zwtpkiq", "bs", "cxqxkx", "hax", "jl", "npe", "lscpi", "ed", "ftxvkrua", "cc", "pdjpxe", "ydygmyfhzg", "dvnblu", "uav", "noy", "as", "htkkdsza", "mwbyxpeoq", "kmyxgapu", "ckv", "eixlb", "ld", "zhwuwhv", "sdpue", "xiraxbfix", "jqrg", "gol", "puh", "wduttks", "yckdpqndre", "a", "xvtbbcy", "musvxh", "gzwuan", "wosnovbt", "qogmgtg", "gcnu", "httjtkgn", "phsma", "lavsovulj", "onzydl", "lilfs", "dlq", "ujbptgyx", "hmd", "ggvdz", "axa", "yrpopozc", "amnpzpd", "kfdbwerqgj", "pdsyqokl", "dhnryedl", "vfh", "fbypdnb", "yfbagjimq", "fkfdmzcxx", "gwaqofleud", "ookdzziuph", "sqjeqp", "vbkjiktgrx", "rdwvz", "yuivejy", "ekdc", "bebhfm", "jxdzuzv", "bxqwsfoeft", "wmukcbx", "tjid", "vrr", "jqndl", "nvythrkac", "tzvnoklad", "sncmrdji", "auleh", "iyxxpbwz", "mrb", "klwpuzoja", "pdgxywk", "yndyeejbez", "fhfpcda", "ca", "ly", "xxxvhcw", "eqhrr", "ibyxc", "qjxyjhevjg", "vtg", "gqk", "tqvlodhui", "dgtljmzyuz", "iwxvbyq", "fcut", "quhnmpjjom", "xsk", "qeoeobsioy", "exm", "dmv", "blr", "axajnan", "flr", "sx", "fhdjyhxhx", "yoduzza", "gbnyjyybg", "rajcgvpliv", "lm", "heyf", "abenk", "dm", "wvridltx", "eyecpye", "sdmko", "uopvpuicx", "dkhzqx", "sgonyexi", "hwmpksxgx", "hrijxwcb", "ghjibav", "solkma", "onac", "iiimq", "csoiyrbxf", "estbehrh", "loscnjyjvq", "rjaaiilj", "dxb", "wjfeboexkr", "fntovvl", "vapdx", "jznr", "paf", "uc", "lsviwnzjn", "zpb", "vjha", "vwrlb", "ugshazn", "skaiyf", "qozzdjjgy", "xfjcojpo", "nejnnl", "pi", "uxatd", "ososijr", "vrzrpd", "efwzq", "hkmldlht", "av", "lpxnkxricw", "zse", "sqfiahpgpe", "isyqp", "hbuvwpuc", "nyl", "eylltichy", "rkgheqa", "stvue", "rgyfsa", "ylza", "ez", "tfoofmh", "msfgsv", "gtonthqhuq", "paidyxwnjg", "bio", "ioz"});

    cout << my_sol.distinctNames(ideas) << endl;

    return 0;
}