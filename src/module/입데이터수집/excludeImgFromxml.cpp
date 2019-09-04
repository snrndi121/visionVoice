#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// const string PATH_IMG = "/home/uki408/Documents/git/visionVoice/src/입데이터수집/train_data/"
const string IMG_PATH = "./train_data/";
int main()
{
    //xml_file_list
    ifstream ifs_xml("train_data_list_xml.md");
    if (ifs_xml.fail()) {
        // cout<<">train xml, not found." << endl;
        return -1;
    }
    vector < string > xml_list;

    while (!ifs_xml.eof()) {
        string file_xml_name;
        ifs_xml >> file_xml_name;
        xml_list.push_back(file_xml_name);
    }
    cout << "# read xml_list done" << endl;
    //img_file_list
    ifstream ifs("train_data_list_img.md");
    if (ifs.fail()) {
        // cout << ">train img, not found." << endl;
        return -1;
    }
    vector < string > img_list;
    while (!ifs.eof()) {
        string file_img_name;
        ifs >> file_img_name;
        img_list.push_back(file_img_name);
    }
    cout << "# read img_list done" << endl;
    //compare
    int count = 0;
    for (vector < string > ::iterator it = img_list.begin();
        it != img_list.end(); ++it) {
            vector < string > ::iterator it2 = xml_list.begin();
            // cout << "img_name : " << it->substr(0, it->size() - 4) << ", ";
            // cout << "xml_name : " << it2->substr(0, it2->size() - 4) << endl;
            for (; it2 != xml_list.end() && it ->substr(0, it->size() - 4) != it2->substr(0, it2->size() - 4); ++it2);
            if (it2 == xml_list.end()) {
                count ++;
                // cout << *it << endl;
                string fn = (*it);
                fn.insert(0, IMG_PATH);
                cout << fn << endl;
                // remove(fn.c_str());
            }
        }
    cout << " # img count : " << img_list.size() << endl;
    cout << " # pascal Voc xml count : " << xml_list.size() << endl;
    cout << " # filtered count : " << count << endl;
    return 0;
}
