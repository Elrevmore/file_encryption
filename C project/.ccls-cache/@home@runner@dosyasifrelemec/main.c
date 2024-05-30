#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  KEY 5


void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);

int main() {
  char inputFile[100], outputFile[100];
  int choice;

  printf("1. Encrypt File\n");
  printf("2. Decrypt File\n");
  printf("Enter your choice:");
  scanf("%d", &choice);

  printf("Enter input file name:");
  scanf("%s", inputFile);

  printf("Enter output file name:");
  scanf("%s", outputFile);

  switch (choice) {
    case 1:
      encryptFile(inputFile, outputFile);
      break;
    case 2:
      decryptFile(inputFile, outputFile);
      break;
    default:
      printf("Invalid choice.\n");
    
  }

 
  return 0;
}
void encryptFile(const char *inputFile, const char *outputFile)  {
  FILE *inFile, *outFile;
  char ch;

  inFile = fopen(inputFile, "r");
  outFile = fopen(outFile, "w");
  
  if(inFile == NULL || outFile == NULL){
    printf("Unable to open.\n");
    exit(EXIT_FAILURE);
  }
  
  while((ch = fgetc(inFile)) != EOF){
    ch = ch + KEY; // Anahtar değeri ile karakteri kaydır
    fputc(ch, outFile); // Şifrelenmiş karakteri dosyaya yaz
  }
  printf("File encrypted successfully.\n");
  fclose(inFile);
  fclose(outFile);
}


void decryptFile(const char *inputFile, const char *outputFile) {
  FILE *inFile, *outFile;
  char ch;

  
  inFile = fopen(inputFile, "r");
  outFile = fopen(outputFile, "w");

  if(inFile == NULL || outFile == NULL){
    printf("Unable to open.\n");
    exit(EXIT_FAILURE);
  }

  
  while((ch = fgetc(inFile)) != EOF) {
    ch = ch - KEY;
    fputc(ch, outFile);
  }

  printf("File decrypted succesfully.\n");
  fclose(inFile);
  fclose(outFile);
}