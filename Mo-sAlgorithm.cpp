#include <bits/stdc++.h>
using namespace std;

pair< pair<int,int> , int> queries[100050];
long long current_answer;
long long cnt[100050];
long long answers[100050];
int BLOCK_SIZE;
int arr[100050];

bool mo_comp(const pair< pair<int,int>,int > &x,const pair< pair<int,int>,int > &y){
	int block_x = x.first.first/BLOCK_SIZE;
	int block_y = y.first.first/BLOCK_SIZE;
	if(block_x != block_y)
		return block_x < block_y ;
	return x.first.second < y.first.second;
}

void add(int x){
	current_answer -= cnt[x] * cnt[x] * x ;
	cnt[x]++;
	current_answer += cnt[x] * cnt[x] * x ;   
}

void remove(int x){
	current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	BLOCK_SIZE = sqrt(N);
	for(int i=0;i<Q;i++){
		cin >> queries[i].first.first >> queries[i].first.second ;
		queries[i].second = i;
	}
	sort(queries,queries+Q,mo_comp);

	int mo_left = 0,mo_right = -1;
	for(int i=0;i<Q;i++){
		int left = queries[i].first.first;
		int right = queries[i].first.second;

		while(mo_right < right){
			mo_right++;
			add(arr[mo_right]);
		}

		while(mo_right > right){
			remove(arr[mo_right]);
			mo_right--;
		}

		while(mo_left < left){
			remove(arr[mo_left]);
			mo_left++;
		}

		while(mo_left > left){
			mo_left--;
			add(arr[mo_left]);
		}
		answers[queries[i].second] = current_answer;
	}
	for(int i=0;i<Q;i++){
		cout << answers[i] << '\n';
	}
	return 0;
}