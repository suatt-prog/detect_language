#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
const float frequency[2][20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.10, 0.10, 0.10, 0.10, 1.81, 0.73, 0.72, 0.42, 0.42, 0.10, 0.10, 0.10, 0.10, 0.10,
                                0.10, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.10, 0.10, 0.10, 0.10, 0.10, 1.04, 0.76, 0.75, 0.72, 0.62
 };
const char languages[2][7]={"english", "german"};
float distances [2][20];
float calculated_frequencies[2][20];
void calculate_distances(const float deneme[2][20]){
    for(int a=0;a<2;a++){
        for(int b=0;b<20;b++){
            if(deneme[a][b]<frequency[a][b]){
                distances[a][b]=frequency[a][b]-deneme[a][b];
            }
            else
                distances[a][b]=deneme[a][b]-frequency[a][b];
        }
    }
}
void detect_language(){
    float sum=0.0,sum1=0.0;
    for(int c=0;c<20;c++){
        sum+=distances[0][c];
    }
    for(int d=0;d<20;d++){
        sum1+=distances[1][d];
    }
    printf("\n%f   %f\n",sum,sum1);
    for(int a1=0;a1<20;a1++){
        printf("\nAlmanca'nin mesafesi %f\n",distances[1][a1]);
        }
    for(int a2=0;a2<20;a2++){
        printf("\nIngilizce'nin mesafesi %f\n",distances[0][a2]);}
     if(sum>sum1){
        printf("Girdiginiz metin Almanca ile yazilmistir");
    }
    else{
        printf("Girdiginiz metin Ingilizce ile yazilmistir");}
}




void calculate_frequencies_tri(char str[],int pou){
//islemin daha hızlı olması için 2 degişken var fonksiyonda matriks ve uzunluğu girilmeli
    char matrix_trigram_strings[10][3]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};
    int t=0,l=0,k=0,i=0,sum2=0;
    float asd[2][20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int l=0;l<10;l++){
        i=0;
        for(t=0;t<pou;t++){
            if(matrix_trigram_strings[l][k]==str[t]){
              if(matrix_trigram_strings[l][k+1]==str[t+1]){
                if(matrix_trigram_strings[l][k+2]==str[t+2]){
                    asd[0][l+10]=i+1;
                    i++;
                }
              }
            }
        }
        sum2+=asd[0][l+10];
        }
    for(int e=0;e<2;e++){
    for(int a=0;a<10;a++){
    calculated_frequencies[e][a+10]=asd[0][a+10];
    printf("trigram %f\n",calculated_frequencies[e][a+10]);
}}
}
void filter_str(char str[200])
{
    int i,j;
    char x = ' '; //İstenmeyen karakterler yerine boşluk koymak için önceden boşluğu char cinsinden tanımladım.

    for(i=0; str[i]!='\0'; i++)
      {
          if (!((str[i]>='a'&&str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]=='\0')))
          {
              str[i] = x ;
          }

      }

    //ileride hem büyük hem küçük harfleri aramamak için kullanıcıdan aldığım metni temizledikten sonra harfleri küçülten döngü
    for(int j = 0; str[j]; j++)
    {
        str[j] = tolower(str[j]);
    }

  printf("\n%s",str);

  }


void calculate_frequencies_bi(char str[],int g4)
{
    char matrix_bigram_strings[10][2] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};
    int m=0,n=0,a=0,c=0;
    int len=strlen(matrix_bigram_strings);
    float degerler[2][10]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float b=0.0;
    //filter_str(str);


    printf("\n");
    int x=0,y=0;
    for(x=0;x<2;x++)
    {
        for(y=0;y<10;y++)
        {
            b=0;
        for(m=0;m<g4;m++)
            {
        if(str[m]==matrix_bigram_strings[y][0])
        {
            if(str[m+1]==matrix_bigram_strings[y][1])
            {
                degerler[x][y]=b+1;
                b++;
            }
        }
            calculated_frequencies[x][y]=degerler[x][y];

        }printf("biagramlar: %f\n",calculated_frequencies[x][y]);
    }
    }

}



int main(){
    char metin[1000];
    gets(metin);
    filter_str(metin);
    calculate_frequencies_bi(metin,1000);
    calculate_frequencies_tri(metin,1000);
    calculate_distances(calculated_frequencies);
    detect_language();
    return 0;
}