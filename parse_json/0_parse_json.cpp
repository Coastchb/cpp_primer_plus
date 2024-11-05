#include <deque>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace std;

struct FeatureUnitConfig {
    vector<int32_t> slotIds;
    int32_t slotId;
    std::string crossType;
    vector<std::string> pkNames;
    std::string featureType;
    //KCFG_DEFINE_FIELDS(slotIds, slotId, crossType, pkNames, featureType)
};

const rapidjson::Value* getJsonFiledValue(const rapidjson::Value& json, const char* name) {
    if (!name[0]) {
        return &json;
    }
    rapidjson::Value::ConstMemberIterator found = json.FindMember(name);
    if (found == json.MemberEnd()) {
        return NULL;
    }
    return &(found->value);
}

template <typename K>
bool Parse(const rapidjson::Value& json, const char* name, std::set<K>& v) {
    const rapidjson::Value* val = getJsonFiledValue(json, name);
    if (NULL == val) {
        return false;
    }
    if (!val->IsArray()) {
        return false;
    }
    v.clear();
    for (rapidjson::Value::ConstValueIterator ait = val->Begin(); ait != val->End(); ++ait) {
        K tmp;
        if (Parse(*ait, "", tmp)) {
            v.insert(tmp);
        } else {
            v.clear();
            return false;
        }
    }
    return true;
}

template <typename T>
bool ParseFromJsonString(const std::string& content, T& v) {
    rapidjson::Document d;
    d.Parse<0>(content.c_str());
    if (d.HasParseError()) {
        return false;
    }
    return Parse(d, "", v);
}

int main() {
    std::vector<FeatureUnitConfig> feature_config;
    std::string content = "[{'slotIds':[1],'crossType':'single','slotId':1,'pkNames':['u-id'],'featureType':'user'},{'slotIds':[2],'crossType':'single','slotId':2,'pkNames':['u-age'],'featureType':'user'},{'slotIds':[3],'crossType':'single','slotId':3,'pkNames':['u-gender'],'featureType':'user'},{'slotIds':[4],'crossType':'single','slotId':4,'pkNames':['u-school'],'featureType':'user'},{'slotIds':[600],'crossType':'single','slotId':600,'pkNames':['u-new-longpro-cateone'],'featureType':'user'},{'slotIds':[601],'crossType':'single','slotId':601,'pkNames':['u-new-longpro-catetwo'],'featureType':'user'},{'slotIds':[27],'crossType':'single','slotId':27,'pkNames':['u-longpro-author'],'featureType':'user'},{'slotIds':[28],'crossType':'single','slotId':28,'pkNames':['u-longpro-topic'],'featureType':'user'},{'slotIds':[602],'crossType':'single','slotId':602,'pkNames':['u-new-shortpro-cateone'],'featureType':'user'},{'slotIds':[603],'crossType':'single','slotId':603,'pkNames':['u-new-shortpro-catetwo'],'featureType':'user'},{'slotIds':[31],'crossType':'single','slotId':31,'pkNames':['u-shortpro-author'],'featureType':'user'},{'slotIds':[32],'crossType':'single','slotId':32,'pkNames':['u-shortpro-topic'],'featureType':'user'},{'slotIds':[604],'crossType':'single','slotId':604,'pkNames':['u-new-socfollow-cateone'],'featureType':'user'},{'slotIds':[605],'crossType':'single','slotId':605,'pkNames':['u-new-socfollow-catetwo'],'featureType':'user'},{'slotIds':[35],'crossType':'single','slotId':35,'pkNames':['u-socfollow-author'],'featureType':'user'},{'slotIds':[36],'crossType':'single','slotId':36,'pkNames':['u-socfollow-topic'],'featureType':'user'},{'slotIds':[37],'crossType':'single','slotId':37,'pkNames':['u-socfollow-selfauthor'],'featureType':'user'},{'slotIds':[606],'crossType':'single','slotId':606,'pkNames':['u-new-socqq-cateone'],'featureType':'user'},{'slotIds':[607],'crossType':'single','slotId':607,'pkNames':['u-new-socqq-catetwo'],'featureType':'user'},{'slotIds':[40],'crossType':'single','slotId':40,'pkNames':['u-socqq-author'],'featureType':'user'},{'slotIds':[41],'crossType':'single','slotId':41,'pkNames':['u-socqq-topic'],'featureType':'user'},{'slotIds':[100],'crossType':'single','slotId':100,'pkNames':['u-extpro-game-pay-cnt-tags','featureType':'user'],{'slotIds':[101],'crossType':'single','slotId':101,'pkNames':['u-extpro-game-pay-amt-tags'],'featureType':'user'},{'slotIds':[102],'crossType':'single','slotId':102,'pkNames':['u-extpro-game-pay-days-tags'],'featureType':'user'},{'slotIds':[103],'crossType':'single','slotId':103,'pkNames':['u-extpro-game-login-cnt-tags'],'featureType':'user'},{'slotIds':[104],'crossType':'single','slotId':104,'pkNames':['u-extpro-game-online-time-tags'],'featureType':'user'},{'slotIds':[105],'crossType':'single','slotId':105,'pkNames':['u-extpro-tx-video-tags'],'featureType':'user'},{'slotIds':[106],'crossType':'single','slotId':106,'pkNames':['u-extpro-inner-conn-app-tags'],'featureType':'user'},{'slotIds':[107],'crossType':'single','slotId':107,'pkNames':['u-extpro-inner-conn-app-ids'],'featureType':'user'},{'slotIds':[110],'crossType':'single','slotId':110,'pkNames':['u-extpro-news-tags'],'featureType':'user'},{'slotIds':[111],'crossType':'single','slotId':111,'pkNames':['u-extpro-news-cats'],'featureType':'user'},{'slotIds':[112],'crossType':'single','slotId':112,'pkNames':['u-extpro-group-tags'],'featureType':'user'},{'slotIds':[457],'crossType':'single','slotId':457,'pkNames':['ev-author-20t'],'featureType':'user'},{'slotIds':[458],'crossType':'single','slotId':458,'pkNames':['ea-author-20t'],'featureType':'user'},{'slotIds':[459],'crossType':'single','slotId':459,'pkNames':['ev-cateone-20t'],'featureType':'user'},{'slotIds':[460],'crossType':'single','slotId':460,'pkNames':['ea-cateone-20t'],'featureType':'user'},{'slotIds':[461],'crossType':'single','slotId':461,'pkNames':['ev-catetwo-20t'],'featureType':'user'},{'slotIds':[462],'crossType':'single','slotId':462,'pkNames':['ea-catetwo-20t'],'featureType':'user'},{'slotIds':[463],'crossType':'single','slotId':463,'pkNames':['ev-topic-20t'],'featureType':'user'},{'slotIds':[464],'crossType':'single','slotId':464,'pkNames':['ea-topic-20t'],'featureType':'user'},{'slotIds':[465],'crossType':'single','slotId':465,'pkNames':['ev-dssmcid-20t'],'featureType':'user'},{'slotIds':[466],'crossType':'single','slotId':466,'pkNames':['ea-dssmcid-20t'],'featureType':'user'},{'slotIds':[467],'crossType':'single','slotId':467,'pkNames':['ev-imagecid-20t'],'featureType':'user'},{'slotIds':[468],'crossType':'single','slotId':468,'pkNames':['ea-imagecid-20t'],'featureType':'user'},{'slotIds':[480],'crossType':'single','slotId':480,'pkNames':['ev-author-60t'],'featureType':'user'},{'slotIds':[481],'crossType':'single','slotId':481,'pkNames':['ea-author-60t'],'featureType':'user'},{'slotIds':[482],'crossType':'single','slotId':482,'pkNames':['ev-cateone-60t'],'featureType':'user'},{'slotIds':[483],'crossType':'single','slotId':483,'pkNames':['ea-cateone-60t'],'featureType':'user'},{'slotIds':[484],'crossType':'single','slotId':484,'pkNames':['ev-catetwo-60t'],'featureType':'user'},{'slotIds':[485],'crossType':'single','slotId':485,'pkNames':['ea-catetwo-60t'],'featureType':'user'},{'slotIds':[486],'crossType':'single','slotId':486,'pkNames':['ev-topic-60t'],'featureType':'user'},{'slotIds':[487],'crossType':'single','slotId':487,'pkNames':['ea-topic-60t'],'featureType':'user'},{'slotIds':[488],'crossType':'single','slotId':488,'pkNames':['ev-dssmcid-60t'],'featureType':'user'},{'slotIds':[489],'crossType':'single','slotId':489,'pkNames':['ea-dssmcid-60t'],'featureType':'user'},{'slotIds':[490],'crossType':'single','slotId':490,'pkNames':['ev-imagecid-60t'],'featureType':'user'},{'slotIds':[491],'crossType':'single','slotId':491,'pkNames':['ea-imagecid-60t'],'featureType':'user'},{'slotIds':[500],'crossType':'single','slotId':500,'pkNames':['ev-author-150t'],'featureType':'user'},{'slotIds':[501],'crossType':'single','slotId':501,'pkNames':['ea-author-150t'],'featureType':'user'},{'slotIds':[502],'crossType':'single','slotId':502,'pkNames':['ev-cateone-150t'],'featureType':'user'},{'slotIds':[503],'crossType':'single','slotId':503,'pkNames':['ea-cateone-150t'],'featureType':'user'},{'slotIds':[504],'crossType':'single','slotId':504,'pkNames':['ev-catetwo-150t'],'featureType':'user'},{'slotIds':[505],'crossType':'single','slotId':505,'pkNames':['ea-catetwo-150t'],'featureType':'user'},{'slotIds':[506],'crossType':'single','slotId':506,'pkNames':['ev-topic-150t'],'featureType':'user'},{'slotIds':[507],'crossType':'single','slotId':507,'pkNames':['ea-topic-150t'],'featureType':'user'},{'slotIds':[508],'crossType':'single','slotId':508,'pkNames':['ev-dssmcid-150t'],'featureType':'user'},{'slotIds':[509],'crossType':'single','slotId':509,'pkNames':['ea-dssmcid-150t'],'featureType':'user'},{'slotIds':[510],'crossType':'single','slotId':510,'pkNames':['ev-imagecid-150t'],'featureType':'user'},{'slotIds':[511],'crossType':'single','slotId':511,'pkNames':['ea-imagecid-150t'],'featureType':'user'},{'slotIds':[200],'crossType':'single','slotId':200,'pkNames':['i-id'],'featureType':'item'},{'slotIds':[201],'crossType':'single','slotId':201,'pkNames':['i-author'],'featureType':'item'},{'slotIds':[202],'crossType':'single','slotId':202,'pkNames':['i-cateone'],'featureType':'item'},{'slotIds':[203],'crossType':'single','slotId':203,'pkNames':['i-catetwo'],'featureType':'item'},{'slotIds':[204],'crossType':'single','slotId':204,'pkNames':['i-topic'],'featureType':'item'},{'slotIds':[205],'crossType':'single','slotId':205,'pkNames':['i-grade'],'featureType':'item'},{'slotIds':[206],'crossType':'single','slotId':206,'pkNames':['i-datatype'],'featureType':'item'},{'slotIds':[628],'crossType':'single','slotId':628,'pkNames':['a-new-poppro-cateone'],'featureType':'item'},{'slotIds':[629],'crossType':'single','slotId':629,'pkNames':['a-new-poppro-catetwo'],'featureType':'item'},{'slotIds':[302],'crossType':'single','slotId':302,'pkNames':['a-poppro-topic'],'featureType':'item'},{'slotIds':[303],'crossType':'single','slotId':303,'pkNames':['a-poppro-itemid'],'featureType':'item'},{'slotIds':[308],'crossType':'single','slotId':308,'pkNames':['a-fans'],'featureType':'item'},{'slotIds':[309],'crossType':'single','slotId':309,'pkNames':['a-publish'],'featureType':'item'},{'slotIds':[310],'crossType':'single','slotId':310,'pkNames':['a-clkmax'],'featureType':'item'},{'slotIds':[311],'crossType':'single','slotId':311,'pkNames':['a-pushmax'],'featureType':'item'},{'slotIds':[312],'crossType':'single','slotId':312,'pkNames':['a-favourmax'],'featureType':'item'},{'slotIds':[313],'crossType':'single','slotId':313,'pkNames':['a-commentmax'],'featureType':'item'},{'slotIds':[314],'crossType':'single','slotId':314,'pkNames':['a-expmax'],'featureType':'item'}]";
    std::replace(content.begin(), content.end(), '\'', '\"');
    ParseFromJsonString(content, feature_config);
}