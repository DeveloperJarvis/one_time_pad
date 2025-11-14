#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Safe fopen macro for MSVC compatibility
#if defined(_MSC_VER)
#define FOPEN(fptr, filename, mode) fopen_s(&fptr, filename, mode)
#else
#define FOPEN(fptr, filename, mode) (fptr = fopen(filename, mode))
#endif

void encrypt(FILE *secret_file, FILE *encrypted_file, FILE *key_file)
{
	int c;
	while ((c = fgetc(secret_file)) != EOF)
	{
		unsigned char key = rand() & 0xFF; // keep only 8 bits
		unsigned char encrypted_c = (unsigned char)c ^ key;

		fputc(key, key_file);
		fputc(encrypted_c, encrypted_file);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file-to-encrypt>\n", argv[0]);
		return 1;
	}

	srand((unsigned)time(NULL)); // IMPORTANT

	char *secret_file_name = argv[1];

	FILE *secret_file;
	FOPEN(secret_file, secret_file_name, "rb");

	FILE *encrypted_file;
	FOPEN(encrypted_file, "crypt.bin", "wb");

	FILE *key_file;
	FOPEN(key_file, "key.bin", "wb");

	if (!secret_file || !encrypted_file || !key_file)
	{
		printf("Error opening files.\n");
		return 1;
	}

	encrypt(secret_file, encrypted_file, key_file);

	fclose(secret_file);
	fclose(encrypted_file);
	fclose(key_file);

	printf("Encryption complete.\n");
	return 0;
}
