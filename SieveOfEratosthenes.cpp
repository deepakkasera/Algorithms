#include <bits/stdc++.h>
using namespace std;
int isPrime[1000005];
int minPrime[1000005];
void sieveOfEratosthenes(int n){
	for(int i=0;i<=n;i++)
		isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	for(int i=2;i<=n;i++){
		if(isPrime[i] == 1){
			for(int j=i*i;j<=n;j+=i)
				isPrime[j]=0;
		}
	}
	return ;
}

//fast factorization
std::vector<int> v;
int k;
std::vector<int> factorization(int n){
	std::vector<int> res;
	//res.push_back(1);
	for(int i=2;i*i<=n;i++){
		while(n%i == 0){
			res.push_back(i);
			n/=i;
		}
	}
	if(n!=1) res.push_back(n);
	return res;
}

// void function(int n){
// 	int minPrime[n+1];
// 	for(int i=0;i<=n;i++)
// 		minPrime[i] = !isPrime[i];
// 	for(int i=2;i*i<=n;i++){
// 		if(minPrime[i] == 0){   
// 			for(int j=i*i;j<=n;j+=i){
// 				if(minPrime[j] == )
// 					minPrime[j] = ;
// 			}
// 		}
// 	}
// }

// log(n) factorization
std::vector<int> factorizationlog(int n){
	for(int i=0;i<=n;i++)
		minPrime[i] = 0;
	minPrime[0] = minPrime[1] = 1;
	for(int i=2;i*i<=n;i++){
		if(minPrime[i] == 0){     /// if i is prime
			for(int j=i*i;j<=n;j+=i){
				if(minPrime[j] == 0)
					minPrime[j] = i;
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(minPrime[i] == 0)
			minPrime[i] =  i;
	}

	std::vector<int> res;
	std::map<int,int> m;
	std::map<int,int>::iterator it;
		while(n != 1){
			res.push_back(minPrime[n]);
			m[minPrime[n]]++;
			n /= minPrime[n];
	}
	cout << "map is \n";
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	return res;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	sieveOfEratosthenes(n);
	for(int i=2;i<=n;i++){
		if(isPrime[i])
			cout << i << " ";
	}
	cout << "\n";
	std::vector<int> factors = factorization(n);
	for(int i=0;i<factors.size();i++)
		cout << factors[i] << " ";
	cout << endl;
	//cout << n << "\n";
	std::vector<int> factors2 = factorizationlog(n);
	for(int i=0;i<factors2.size();i++)
		cout << factors2[i] << " ";
	return 0;
}