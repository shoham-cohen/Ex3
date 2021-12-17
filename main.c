#include <stdio.h>

#define WORD 30
#define TXT 1024

int main(){
   char initialword[WORD];
   int wordLength = 0;
   scanf("%s", initialword);
   //count the letters in the word//
   for(int i = 0; i < WORD; i++){
      if(initialword[i] >= 'A' && initialword[i] <= 'Z'){
         wordLength++;
      }
      else if(initialword[i] >= 'a' && initialword[i] <= 'z'){
         wordLength++;
      }
      else{
      break;
      }
   }
   //creat new array in the length of the word which will contain only the letters of the word//
   char word[wordLength];
   for(int i = 0; i < wordLength; i++){
      word[i] = initialword[i];
   }
   //fill the txt array with 0 before collecting the txt//
   char txt[TXT];
   for(int i = 0; i < TXT; i++){
      txt[i] = 0;
   }
   //collect the txt//
   scanf("%[^~]s", txt);
   //calculate the gemetric value of the word//
   int value = 0;
   for (int i = 0; i < wordLength; i++){ 
      if (word[i] >= 'A' && word[i] <= 'Z'){
         value += word[i] - 'A' + 1;
      }
      else if (word[i] >= 'a' && word[i] <= 'z'){
         value += word[i] - 'a' + 1;
      }   
   }
   //start of the gemetric function//
   printf("Gematria Sequences: ");
   int start = 0;
   int currValue = 0;
   int i = 0;
   int firstPrint = 0;
   while(start < TXT){
      if (txt[i] >= 'A' && txt[i] <= 'Z'){
         if (currValue + txt[i] - 'A' + 1 < value){
           if(currValue == 0){
              start = i;
              currValue += txt[i] - 'A' + 1;
              i++;
           }
           else{
              currValue += txt[i] - 'A' + 1;
              i++;
           }
         }
         else if(currValue + txt[i] - 'A' + 1 > value){
            currValue = 0;
            start++;
            i = start;
         }
         else if(currValue + txt[i] - 'A' + 1 == value){
            if(firstPrint == 1){
               printf("~");
            }
            for(int j = start; j <= i; j++){
              printf("%c", txt[j]);
            }
            start++;
            i = start;
            currValue = 0; 
            firstPrint = 1;
         }
      }
      else if (txt[i] >= 'a' && txt[i] <= 'z'){
         if (currValue + txt[i] - 'a' + 1 < value){
           if(currValue == 0){
              start = i;
              currValue += txt[i] - 'a' + 1;
              i++;
           }
           else{
              currValue += txt[i] - 'a' + 1;
              i++;
           }
         }
         else if(currValue + txt[i] - 'a' + 1 > value){
            currValue = 0;
            start++;
            i = start;
         }
         else if(currValue + txt[i] - 'a' + 1 == value){
            if(firstPrint == 1){
               printf("~");
            }
            for(int j = start; j <= i; j++){
              printf("%c", txt[j]);
            }
            start++;
            i = start;
            currValue = 0;
            firstPrint = 1; 
         }
      }
      else{
        i++;
      }
   }
   putchar('\n');
   start = 0;
   printf("Atbash Sequences: ");
   firstPrint = 0;
   int wordIndex = 1; 
   char reverse[wordLength];
   for(int j = 0; j < wordLength; j++){
      reverse[j] = word[wordLength - j - 1];
   }
   while(start < TXT){
      if(txt[start] + word[0] == 155 || txt[start] + word[0] == 219){
         wordIndex = 1;
         for(i = 1; wordIndex < wordLength; i++){
            if(start + i > TXT){
               start += start + i;
               break;
            }
            else if (txt[start + i] >= 'A' && txt[start + i] <= 'Z'){
               if(txt[start + i] + word[wordIndex] != 155){
                  start++;
                  break;
               }
               else{
                  wordIndex++;
               }
            }
            else if (txt[start + i] >= 'a' && txt[start + i] <= 'z'){
               if(txt[start + i] + word[wordIndex] != 219){
                  start++;
                  break;
               }
               else{
                  wordIndex++;
               }
            }
            else if(txt[start + i] != ' ' && txt[start + i] != '\t' && txt[start + i] != '\n'){
               start++;
               break;
            }
         }
         if(wordIndex == wordLength){
            if(firstPrint == 1){
               printf("~");
            }
            for(int j = start; j < start + i; j++){
               printf("%c", txt[j]);
            }
            firstPrint = 1;
            start++;
         }
      }
      else if(txt[start] + reverse[0] == 155 || txt[start] + reverse[0] == 219){
         wordIndex = 1;
         for(i = 1; wordIndex < wordLength; i++){
            if(start + i > TXT){
               start += start + i;
               break;
            }
            else if (txt[start + i] >= 'A' && txt[start + i] <= 'Z'){
               if(txt[start + i] + reverse[wordIndex] != 155){
                  start++;
                  break;
               }
               else{
                  wordIndex++;
               }
            }
            else if (txt[start + i] >= 'a' && txt[start + i] <= 'z'){
               if(txt[start + i] + reverse[wordIndex] != 219){
                  start++;
                  break;
               }
               else{
                  wordIndex++;
               }
            }
            else if(txt[start + i] != ' ' && txt[start + i] != '\t' && txt[start + i] != '\n'){
               start++;
               break;
            }
         }
         if(wordIndex == wordLength){
            if(firstPrint == 1){
               printf("~");
            }
            for(int j = start; j < start + i; j++){
               printf("%c", txt[j]);
            }
            firstPrint = 1;
            start++;
         }
      }
      else{
        start++;
      }
    }
   printf("\n");
   start = 0;
   int arr[wordLength];
   for(int j = 0; j < wordLength; j++){
      arr[j] = 0;
   }
   int flag = 0;
   int entered = 0;
   int equels = 0;
   int finish = 0;
   firstPrint = 0;
   printf("Anagram Sequences: ");
   while (start < TXT){
      for(int j = 0; j < wordLength; j++){
         if(txt[start] == word[j]){
            arr[j] = 1;
            flag = 1;
            j = wordLength;
         }
      }
      if(flag == 1){
         i = start + 1;
         while(flag == 1){
            entered = 0;
            if(txt[i] == txt[start]){ ////////
               start++;
               entered = 1;
               flag = 0;
               }
            if(entered == 0){
               if(txt[i] == ' ' || txt[i] == '\t' || txt[i] == '\n'){
                  i++;
                  entered = 1;
               }
            }
            if(entered == 0){
               equels = 0;
               finish = 0;
               for(int j = 0; j < wordLength; j++){
                  if(txt[i] == word[j]){
                     equels = 1;
                     arr[j] = 1;
                  }
               }
                  if(equels == 1){
                     for(int j = 0; j < wordLength; j++){
                        if(arr[j] == 0){
                           finish = -1;
                        }
                     }
                     if(finish != -1){
                        if(firstPrint == 1){
                           printf("~");
                        }
                        for(int j = start; j <= i; j++){
                           printf("%c", txt[j]);
                        }
                        firstPrint = 1;
                        start++;
                        i = start + 1;
                        for(int j = 0; j < wordLength; j++){
                           arr[j] = 0;
                        } 
                     }
                     else{
                        i++;
                     }
                  }
                  else{
                     start++;
                     for(int j = 0; j < wordLength; j++){
                        arr[j] = 0;
                     }
                     flag = 0;
                  }
            }         
         } 
      }
      else{
         start++;
      }     
   }
   putchar('\n');
}





