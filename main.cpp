#include <iostream>
#include <cmath>
#include <fstream>
#include <streambuf>
#include <chrono>
#include <ctime>

using namespace std;

char raide (int r1, char r11)
{
    if (r1 == 1)
        r11 = 'A';
    else if (r1 == 2)
        r11 = 'a';
    else if (r1 == 3)
        r11 = 'B';
    else if (r1 == 4)
        r11 = 'b';
    else if (r1 == 5)
        r11 = 'C';
    else if (r1 == 6)
        r11 = 'c';
    else if (r1 == 7)
        r11 = 'D';
    else if (r1 == 8)
        r11 = 'd';
    else if (r1 == 9)
        r11 = 'e';
    else
        r11 = 'f';

    return r11;
}

string hashas (string eil)
{
    string pak, hesh;
    int ilgis, ind = 0, r1, ind2 = 0, i, y, z = 0;
    char r11;
    ilgis = eil.length();
    ind = eil[0];
    y = 1;

    for (int i = 1; i < ilgis; i++)
    {
        if (y == 0)
        {
            ind -= eil[i];
            y++;
        }
        else
        {
            ind += eil[i];
            y--;
        }
    }
    ind = abs(ind);

    for (i = 0; i < ilgis; i++)
    {
        if(hesh.length()>=32)
            break;

        else
        {
            r1 = (eil[i] + ind2)%10;
            hesh += to_string(eil[i]+ind2) + raide(r1, r11);
        }
        ind2++;
    }
    int ind3 = ind;
    int ind4 = ind;
    if (i == ilgis)
    {
        while (hesh.length() < 32)
        {
            ind2 = abs(ind2*2 - ind3*2);
            r1 = ind2%10;
            hesh += to_string(ind2) + raide(r1, r11);

            ind2 += 3;
            ind3 -= 3;
        }
    }
    else
    {
        for (int x = i; x < ilgis; x++)
        {
            if (ind4 > 1000)
                ind4 %= 100;

            r1 = (eil[x] + ind4)%10;
            pak = to_string(eil[x]+ind4) + raide(r1, r11);

            if (z >= 32)
                z = 0;

            hesh.replace(hesh.begin() + z, hesh.begin()+ z + pak.length(), pak);
            z += pak.length();

            if (x%2 == 0)
                ind4 += 3;
            else
                ind4 -= 2;
        }
    }
    while (hesh.length() > 32)
        hesh.pop_back();

    return hesh;
}

int main(int argc, char* argv[])
{
    ifstream fd (argv[1]);
    ofstream fr ("output.txt");

    int pasirinkimas;
    string eil;
    cout << "Norite ivesti ranka (1) ar nuskaityti is failo (2)?" << " ";
    cin >> pasirinkimas;
    if (pasirinkimas == 1)
    {
        cin >> eil;
        fr << hashas(eil) << endl;
    }
    else if (pasirinkimas == 2)
    {
        cout << endl << "Ar norite hash'uoti iskart visa faila (1), ar eilutemis (2)?" << " ";
        cin >> pasirinkimas;
        if (pasirinkimas == 1)
        {
            fd.seekg(0, ios::end);
            eil.reserve(fd.tellg());
            fd.seekg(0, ios::beg);
            eil.assign((istreambuf_iterator<char>(fd)),
            istreambuf_iterator<char>());
            fr << hashas(eil) << endl;
        }
        else
        {
            if (fd.is_open())
            {
                while (std::getline(fd, eil))
                {
                    fr << hashas(eil) << endl;
                }
                fd.close();
            }
        }
    }

    return 0;
}
