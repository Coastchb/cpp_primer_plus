//
// Created by coast on 19-4-29.
//

#include <string>
#include <iostream>
using namespace std;

void compute_wer(const string ref, const string hyp) {
    int ref_size = ref.size();
    int hyp_size = hyp.size();
    int dis[ref_size+1][hyp_size+1];
    char lab[ref_size+1][hyp_size+1];

    dis[0][0] = 0;
    lab[0][0] = ' ';
    for(int i = 1; i <= hyp_size; i++) {
        dis[0][i] = i;
        lab[0][i] = 'I';
    }

    for(int i = 1; i <= ref_size; i++) {
        dis[i][0] = i;
        lab[i][0] = 'D';
    }

    for(int i = 1; i <= ref_size; i++) {
        for(int j = 1; j <= hyp_size; j++) {
            if(ref[i-1] == hyp[j-1]) {
                dis[i][j] = dis[i-1][j-1];
                lab[i][j] = 'C';
                continue;
            }

            if(dis[i-1][j] < dis[i][j-1]) {
              dis[i][j] = dis[i-1][j] + 1;
              lab[i][j] = 'D';
            } else {
                dis[i][j] = dis[i][j-1] + 1;
                lab[i][j] = 'I';
            }
            if(dis[i][j] > dis[i-1][j-1] + 1) {
                dis[i][j] = dis[i-1][j-1] + 1;
                lab[i][j] = 'S';
            }
        }
    }

    if(ref_size)
        cout << "WER: " << float(dis[ref_size][hyp_size]) / ref_size;
    else if(hyp_size != 0)
        cout << "WER: 1";
    else
        cout << "WER: 0";


    char* ali_ref = new char(' ');
    char* ali_hyp = new char(' ');
    char* ali_ret = new char(' ');

    int count = 0;
    int p = ref_size, q = hyp_size;
    while(!(p == 0 && q == 0)) {
        ali_ret[count] = lab[p][q];
        switch(lab[p][q]){
            case 'C':
            case 'S':
                ali_ref[count] = ref[p-1];
                ali_hyp[count] = hyp[q-1];
                p--;
                q--;
                break;
            case 'D':
                ali_ref[count] = ref[p-1];
                ali_hyp[count] = ' ';
                p--;
                break;
            case 'I':
                ali_ref[count] = ' ';
                ali_hyp[count] = hyp[q-1];
                q--;
                break;
        }
        count++;
    }

    cout << "\nref:";
    for(int i = count - 1; i >= 0; i--)
        cout << ali_ref[i] << " ";
    cout << "\nhpy:";
    for(int i = count - 1; i >= 0; i--)
        cout << ali_hyp[i] << " ";
    cout << "\nret:";
    for(int i = count - 1; i >= 0; i--)
        cout << ali_ret[i] << " ";

    cout << endl << endl;
}
int main(int argc, char* argv[]) {
    compute_wer("a", "b");
    compute_wer("abcd", "abc");
    compute_wer("bcb", "cb");
    compute_wer("ab", "bdd");
    compute_wer("", "ab");
    compute_wer("ab", "");
    compute_wer("", "");

    return 0;
}