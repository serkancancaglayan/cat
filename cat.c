/*Serkan Can Caglayan 18120205021
 *
*Semih Demir 18120205005
*Egemen Yapucu 18120205027
*Gorev Dagilimi:
*online platformlar ve irl'de bulusup hep beraber yazdik.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Bu fonksiyon ,programa argüman olarak verilen file'in içeriğini okuyup stdout’a
 göndererek file içeriğini komut satırında gösterir.*/
void opsiyonsuz_okuma(int argc, char **argv)
{
  char c;
  for (int i = 1; i < argc; i++)
  {
    FILE *f = fopen(argv[i], "r");
    if (f == NULL)
    {
      fprintf(stderr, "'%s' adlı dosya bulunamadı.\n", argv[i]);
      exit(EXIT_FAILURE);
    }
    while ((c = fgetc(f)) != EOF)
    {
      printf("%c", c);
    }
    fclose(f);
  }
}
/*Bu fonksiyon ,programa argüman olarak verilen file'in içeriğini okuyup stdout’a
 göndererek file içeriğini,tum satirlari numaralandirarak komut satırında gösterir.*/
void opsiyonlu_okuma1(int argc, char **argv)
{
  char c;
  int line = 1;
  for (int i = 1; i < argc; i++)
  {
    if ((strcmp(argv[i], "-n")) != 0)
    {
      FILE *f = fopen(argv[i], "r");
      if (f == NULL)
      {
        fprintf(stderr, "'%s' adlı dosya bulunamadı.\n", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((c = fgetc(f)) != EOF)
      {
        if (c == '\n')
        {
          printf(" ->%d\n", line++);
        }
        else
        {
          printf("%c", c);
        }
      }
      fclose(f);
    }
  }
}
/*Bu fonksiyon ,programa argüman olarak verilen file'in içeriğini okuyup stdout’a
 göndererek file içeriğini,sadece dolu satirlari numaralandirarak komut satırında gösterir.*/
void opsiyonlu_okuma2(int argc, char **argv)
{
  char c;
  char x;
  int line = 1;
  for (int i = 1; i < argc; i++)
  {
    if ((strcmp(argv[i], "-b")) != 0)
    {
      FILE *f = fopen(argv[i], "r");
      if (f == NULL)
      {
        fprintf(stderr, "'%s' adlı dosya bulunamadı.\n", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((c = fgetc(f)) != EOF)
      {
        if (c == '\n')
        {
          /*bir sonraki karaktere baktik,bos degilse satir numarasi ekledik*/
          if ((x = fgetc(f)) != '\n' || (x = fgetc(f)) != '\t' || (x = fgetc(f)) != ' ')
          {
            printf(" ->%d", line++);
          }
        }
        printf("%c", c);
      }
      fclose(f);
    }
  }
}
/*Bu fonksiyon, programa arguman olarak verilen isimde bir file olusturur ve
bu file'in icine kullanicinin girdigi metni yazar*/
void olusturma_ve_icineyazma(int argc, char **argv)
{
  char c;
  FILE *f = fopen(argv[argc - 1], "w");
  if (f == NULL)
  {
    fprintf(stderr, "Dosya olusturulamadi veya bulunamadi");
  }
  while ((c = getchar()) != EOF)
  {
    putc(c, f);
  }
  fclose(f);
}
/*Bu fonksiyon, programa arguman olarak verilen isimde bir file olusturur ve
bu file'in icine tum satirlari numaralandırarak kullanicinin girdigi metni yazar*/
void olusturma_ve_icineyazma_op1(int argc, char **argv)
{
  char c;
  int linenumber = 1;
  FILE *f = fopen(argv[argc - 1], "w");
  if (f == NULL)
  {
    fprintf(stderr, "Dosya olusturulamadi veya bulunamadi");
  }
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      fprintf(f, "  ->%d", linenumber++);
    }
    putc(c, f);
  }
  fclose(f);
}
/*Bu fonksiyon, programa arguman olarak verilen isimde bir file olusturur ve
bu file'in icine sadece dolu satirlari numaralandırarak kullanicinin girdigi metni yazar*/
void olusturma_ve_icineyazma_op2(int argc, char **argv)
{
  char c;
  char x;
  int linenumber = 1;
  FILE *f = fopen(argv[argc - 1], "w");
  if (f == NULL)
  {
    fprintf(stderr, "Dosya olusturulamadi veya bulunamadi");
  }
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      /*bir sonraki karaktere baktik,bos degilse satir numarasi ekledik*/
      if ((x = fgetc(f)) != '\n' || (x = fgetc(f)) != '\t' || (x = fgetc(f)) != ' ')
      {
        fprintf(f, " ->%d", linenumber++);
      }
    }
    putc(c, f);
  }
  fclose(f);
}
/*Bu fonksiyon bir veya birden fazla dosyanın icerigini verilen hedef
dosyaya kopyalar*/
void opsiyonsuz_yazma(int argc, char **argv)
{
  char c;
  FILE *f = fopen(argv[argc - 1], "w");
  for (int i = 1; i < argc - 1; i++)
  {
    if ((strcmp(argv[i], ">")) != 0)
    {
      FILE *a = fopen(argv[i], "r");
      if (a == NULL)
      {
        fprintf(stderr, "%s isimli dosya bulunamadi.", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((c = fgetc(a)) != EOF)
      {
        fputc(c, f);
      }
      fclose(a);
    }
  }
  fclose(f);
}
/*Bu fonksiyon bir veya birden fazla dosyanın icerigini verilen hedef
dosyaya tum satirlari numaralandirak kopyalar*/
void opsiyonlu_yazma1(int argc, char **argv)
{
  char c;
  int line = 1;
  FILE *f = fopen(argv[argc - 1], "w");
  for (int i = 1; i < argc - 1; i++)
  {
    if ((strcmp(argv[i], ">")) != 0 && (strcmp(argv[i], "-n")) != 0)
    {
      FILE *a = fopen(argv[i], "r");
      if (a == NULL)
      {
        fprintf(stderr, "%s isimli dosya bulunamadi.", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((c = fgetc(a)) != EOF)
      {
        if (c == '\n')
        {
          fprintf(f, " ->%d", line++);
        }
        fputc(c, f);
      }

      fclose(a);
    }
  }
  fclose(f);
}
/*Bu fonksiyon bir veya birden fazla dosyanın icerigini verilen hedef
dosyaya sadece dolu satirlari numaralandirak kopyalar*/
void opsiyonlu_yazma2(int argc, char **argv)
{
  char c;
  char x;
  int line = 1;
  FILE *f = fopen(argv[argc - 1], "w");
  for (int i = 1; i < argc - 1; i++)
  {
    if ((strcmp(argv[i], ">")) != 0 && (strcmp(argv[i], "-b")) != 0)
    {
      FILE *a = fopen(argv[i], "r");
      if (a == NULL)
      {
        fprintf(stderr, "%s isimli dosya bulunamadi.", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((c = fgetc(a)) != EOF)
      {
        if (c == '\n')
        {
          /*bir sonraki karaktere baktik,bos degilse satir numarasi ekledik*/
          if ((x = fgetc(f)) != '\n' || (x = fgetc(f)) != '\t' || (x = fgetc(f)) != ' ')
          {
            fprintf(f, " ->%d", line++);
          }
        }
        fputc(c, f);
      }
      fclose(a);
    }
  }
  fclose(f);
}
/*Bu fonksiyon ,kullaniciya cat komutunun nasil kullanilacagi
 konusunda yardim metni yazdirir*/
void help()
{
  puts("\nKomutun dogru kullanim ornekleri asagidakilerdir:\n\n"
       "\">\" operatoru cikisi kendinden sonraki dosyaya yonlendirir.\n"
       "Dosya olusturma ve icine yazmak: cat \">\" filename\n"
       "Dosya icerigini okumak : cat filename\n"
       "Dosya icerigini kopyalamak,baska bir dosyaya yazmak: cat filename1 \">\" filename2\n"
       "Birden fazla dosyayi baska dosyaya yazmak,kopyalamak: cat filename1 filename2 \">\" filename3\n"
       "\nOpsiyonlar \n"
       "-b opsiyonu:Bos olmayan satirlari numaralandirir\n"
       "-n opsiyonu:Tum satırları numaralandirir\n"
       "-h opsiyonu:Yardım metni yazdirir\n"
       "\nOrnek Kullanımlar\n\n"
       "cat -b file1.txt file2.txt\n"
       "cat -b file1.txt “>” file2.txt\n"
       "cat -b “>” file1.txt\n"
       "cat -b file1.txt\n"
       "cat -h\n");
}
/*Bu fonksiyon verilen argumanların icinde ">" stringinin olup olmadığını kontrol eder*/
int control(int argc, char **argv)
{
  int sayac = 1;
  for (int i = 0; i < argc; i++)
  {
    if (!(strcmp(argv[i], ">")))
    {
      sayac = 0;
    }
  }
  return sayac;
}
/*Bu fonksiyon verilen argümanların icinde opsiyon olup olmadigini kontrol eder*/
int opsiyonvarmi(int argc, char **argv)
{
  int sayac = 1;
  for (int i = 0; i < argc; i++)
  {
    if (!(strcmp(argv[i], "-b")) || !(strcmp(argv[i], "-n")) || !(strcmp(argv[i], "-h")))
    {
      sayac = 0;
    }
  }
  return sayac;
}
int main(int argc, char **argv)
{
  if (!(strcmp(argv[1], "-h")))
  {
    help();
  }
  else if (argc == 4 && !(strcmp(argv[2], ">")) && !(strcmp(argv[1], "-n")))
  {
    olusturma_ve_icineyazma_op1(argc, argv);
  }
  else if (argc == 4 && !(strcmp(argv[2], ">")) && !(strcmp(argv[1], "-b")))
  {
    olusturma_ve_icineyazma_op2(argc, argv);
  }
  else if (argc == 3 && !(strcmp(argv[1], ">")) && opsiyonvarmi(argc, argv))
  {
    olusturma_ve_icineyazma(argc, argv);
  }
  else if (argc >= 4 && !(strcmp(argv[argc - 2], ">")) && !(strcmp(argv[1], "-n")))
  {
    opsiyonlu_yazma1(argc, argv);
  }
  else if (argc >= 4 && !(strcmp(argv[argc - 2], ">")) && !(strcmp(argv[1], "-b")))
  {
    opsiyonlu_yazma2(argc, argv);
  }
  else if (argc >= 4 && !(strcmp(argv[argc - 2], ">")))
  {
    opsiyonsuz_yazma(argc, argv);
  }
  else if (argc >= 2 && (control(argc, argv)) && !(strcmp(argv[1], "-n")))
  {
    opsiyonlu_okuma1(argc, argv);
  }
  else if (argc >= 2 && (control(argc, argv)) && !(strcmp(argv[1], "-b")))
  {
    opsiyonlu_okuma2(argc, argv);
  }
  else if (argc >= 2 && (control(argc, argv)) && opsiyonvarmi(argc, argv))
  {
    opsiyonsuz_okuma(argc, argv);
  }
  else
  {
    puts("Yanlis komut kullanimi.\n");
    help();
  }
  return 0;
}
