#include <iostream>
#include <stdexcept>
#include <cmath>
#include <ctime>
using namespace std;

bool JeProst(long long int n)                 //funkcija za provjeru parnosti
{
    if(n==2) return 1;
    if(n&1==0) return 0;                //prva optimizacija: provjera parnosti preko bitova. Ne koristimo modulus, stedimo vrijeme.
    if(n==3) return 1;
    if(n%3==0) return 0;                //rijesili smo provjeru pri dijeljenju sa brojem 2 (ovaj red iznad), a sada cemo jos i sa brojem 3
    for(long long int i=1;(6*i-1)<=sqrt(n);i++)   // u prethodnim koracima smo provjerili djeljivost sa 2 i 3. Ostali prosti brojevi su oblika 6k+/-1
    {
        if(n%(6*i+1)==0) return 0;
        if(n%(6*i-1)==0) return 0;
    }                                   // Ovo je mnogo brze od onog slucaja kada bi testirali do n ili n/2 ili sqrt(n) krecuci se po dva clana
    return 1;
}

void Goldbach (int n, int& p, int& q)
{
    if(n<=2||n&1) throw domain_error("Neispravan unos.");
    if(n==4)
    {
        p=2;
        q=2;
    }
    for(int i=3;i<=n/2;i+=2)
    {
        if(JeProst(i)&&JeProst(n-i))
        {
            p=i;
            q=n-i;
            break;
        }
    }
}


int main()
{
    long long int n,p,q;

    cin>>n;


    clock_t vrijeme1=clock();
    //Goldbach(n,p,q);
    cout<<JeProst(n)<<endl;
    clock_t vrijeme2=clock();
    //cout<<p<<"  "<<q<<endl;
    cout<<vrijeme2-vrijeme1<<endl;
    cout<<n;
    return 0;
}

