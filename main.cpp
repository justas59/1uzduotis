#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

string hashas (string eil)
{
    string hesh;
    int ilgis, ind = 0, r1, ind2 = 0, i;
    char r11;
    ilgis = eil.length();
    ind = eil[0];
    for (int i=1; i<ilgis; i++)
    {
        if (i%2!=0)
            ind-=eil[i];
        else
            ind+=eil[i];
    }
    ind = abs(ind);

    for (i=0; i<ilgis; i++)
    {
        if(hesh.length()>=32)
        {
            break;
        }
        else
        {
            r1 = (eil[i] + ind2)%10;
            if (r1 == 1 || r1 == 2)
                r11 = 'a';
            else if (r1 == 3 || r1 == 4)
                r11 = 'b';
            else if (r1 == 5 || r1 == 6)
                r11 = 'c';
            else if (r1 == 7 || r1 == 8)
                r11 = 'd';
            else if (r1 == 9)
                r11 = 'e';
            else

            hesh+=to_string(eil[i]+ind2) + r11;
        }
        ind2++;
    }
    int ind3 = ind;
    if (i == eil.length())
    {
        while (hesh.length() < 32)
        {
            ind2 = abs(ind2*2 - ind3*2);
            r1=ind2%10;
            if (r1 == 1 || r1 == 2)
                r11 = 'a';
            else if (r1 == 3 || r1 == 4)
                r11 = 'b';
            else if (r1 == 5 || r1 == 6)
                r11 = 'c';
            else if (r1 == 7 || r1 == 8)
                r11 = 'd';
            else if (r1 == 9)
                r11 = 'e';
            else
                r11 = 'f';
            hesh += to_string(ind2) + r11;

            ind2 += 3;
            ind3 -= 3;
        }
    }
    else
    {

    }
    while (hesh.length() > 32)
        hesh.pop_back();

    return hesh;
}

int main()
{
    ofstream fr ("output.txt");
    int pasirinkimas;
    string eil;
    cout << "Norite ivesti ranka (1) ar nuskaityti is failo (2)?" << endl;
    cin >> pasirinkimas;
    if (pasirinkimas == 1)
    {
        cin >> eil;
    }
    else if (pasirinkimas == 2)
    {

    }

    fr << hashas(eil);


    return 0;
}
