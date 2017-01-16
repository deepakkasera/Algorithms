#include<stdio.h>
int main(){
	char c;
	int i=0;
	char s[]=
	" }Ab h;bZb s|b d,b-c,b-b/b b\\b-d,b-b/b|b c,bZb r_b|b\\b,b'b.b b/b|b g/b|b d`b/b|b-b.bZb n\\b`b.b'b e/b|b g,b m`b;b.bZb m,b'b\\b dAb fAb jAb dAb b_b b/b|b b`b.b;bZb k,b/b c_b oAb h_b c/b b_b d/b|b c;bZb j/b\\b c/b b\\b d,b c,b lAb c/b e/b f`b/b|bZb i/b_b|b b|b b_b b\\b j,b f,b n,b/b c\\bZb h/c b|b b|b/b b`b.b\\b c,b-b g,b h,b d,b/b b,b/b g\\b/bZb h/b b@b|b b|b@b c/b b/b'b d\\b c\\b g,b o>b c/b|b e,b-c.bZb g|b\\b_b/b d\\b_b/b b/b g|b c|b l,b c,b/b i\\b c.b/b'b b_c:b.cZb g|b c_c b_c c|b h|b c|b b.b-c.b c,b j>b c>b d|b-b'b d/b f`bZb e,b/b|b b/b c'b c\\b b|b h|b c|b f\\b g,b l|b e/bZb d/b c|b<b-c.b_c,b-b>b|b h|b c|b b.b e`b.b i>b c>b e/b d(bZb c/b_b,b'b b\\c c^b c/b c\\b f/b c/b d`b.b e>b-c m/b^b\\b d|bZb i\\c_d/b e\\b d/b c/b g\\b_c'b f\\b d\\b d\\b/b d\\b c|bZb j`b.b d|b/b k,b c,b s/b`b\\b e\\b c)bZb l\\b c'b c|b/b e,b hVb e\\b k/b i`b-b\\bZb m`b|b/b c'b cVb gVb l\\b e\\b.b'b m\\b_bZb n'b`b-b.b hVb hVb i\\b.b/b'b\\bZb r`b|b/b-b.b g\\b b/b d\\b b/b,b-d`b\\b jZb s/b d`b.b_fVb_fVb'bZb ~'b f'b";
for(;s[i];i++){
	c=s[i];if(c=='Z')
	c/=9;++i;
	while(s[i]-->'a')
		putchar(c);
    }
  return 0;
}