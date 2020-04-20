#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> boyer_moore(string s, string p) {
    int s_size = s.size();
    int p_size = p.size();
    vector<int> result;

    int i = p_size - 1, j;
    while (i < s_size) {
        j = p_size - 1;

        // ���ڿ� ���� ���� ����
        int idx = i;
        if (s[idx] == p[j]) {
            while (s[idx] == p[j]) {
                idx--;
                j--;
                if (j == -1) break;
            }

            // ���� ��ġ
            if (j == -1) {
                result.push_back(idx + 1);
                i += p_size;
            }
            // ���� ����ġ
            else {
                i += p_size;
            }
        }
        // ���ڿ� ���� �ٸ� ����
        else {
            // �� ���ڰ� ���� ���� �����ϴ��� �˻�
            bool exist = false;
            int k;
            for (k = 0; k < p_size - 1; k++) {
                if (s[idx] == p[k]) {
                    exist = true;
                    break;
                }
            }
            // �����ϴ� ����
            if (exist) {
                i += p_size - k - 1;
            }
            // �������� �ʴ� ����
            else {
                i += p_size;
            }
        }
    }

    return result;
}

int main() {
    string str = "HJKBNNEIIJKDEILKNOMFOOHJGANGNCFEMPFJMKBEDMIHEDBBCNHAMOKCOHIMKNAGNGPJABODNGKBJLDLJKMFIGHGNPCHMDNJJNDJOBMLHGMABPMKJIPBOGILFKDCNALGNOPLPLGGBDHDCDNMLNNJDFEJAHLNIGEFFDBEPHLAKCDNFBJAOGJBMNKMFFJNMNCBBDFALAAFCECHFLHDCAEOOPKDEDAABCBCGHCBHCGKGJBLEJOGJDEHCOKGCKHDNIFDPHEHJKBADCLILKOFNDMPBHFDBMGOFLBECFLMAMMDPHLKBKPONMNODDCEPIDEEEJGKECKBONAGJKHDKGAGDOJGANGJAKNFDDPIGJJEGJKPDCCNICDLBMCBKIKKCHPGLOOBHHFOAANDCABKCEFDBHFLPPFCHFICDGDLNIJNIGAKGBEJGKMHBBCBBHDIMLKABNLOFELOKLIBNNKDHGKIIMJJDMBAHLAIILGNPBLJNEKKBENILHADDKMGGNGOIGGABNNAOJKLNEFOJCGEJGHMADDHAJFIALIBIFCHOMCLAIJJKPNEGEAGHDNHNCPNOHOGNANLMAHNIAGCAEGGIHMAKKHHMHEKODBLDOHAOONGODJOHPEAGBABLHIHONCNADIDBPDANAGMEPKLPPLFALGLDPCBMEOMHHPJGDJEDPAHPKDOJODJKKENJHOFLNBDEAMKDFOHEOODJBBCAFMKPAHIHFNDCOGGOCBCHPJLOHPHJAJJFFDEGKMNPJACHGIGIJIPJBLHIKOBKHKANNEDHBAHKBJCHBIALAPEBKLJEJLPAFPNDDAKEBBPCKBJMJJHJJLKDGDIPOHPEGNHJNBOODNANOKJHDAAMLKABNIAMPAAFNHOKIMJLJJJHDCOHDODOIDAGLACKACPNJOIBKBNEKGLOIKFLIIKBMKHHKJCLLBIEPAFKBCOMIJKBDPMMHGNDAELLNNGIOOMOPBIAEGMMPGNDFKPNAMABALMNICFHABFPCN";
    string pattern = "FCECHFLHDCAEOOPKD";

    vector<int> ans;
    ans = boyer_moore(str, pattern);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
