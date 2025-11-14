#include <stdio.h>
#include <stdlib.h>

// fopen compatibility macro for MSVC and GCC
#if defined(_MSC_VER)
#define FOPEN(fptr, filename, mode) fopen_s(&fptr, filename, mode)
#else
#define FOPEN(fptr, filename, mode) (fptr = fopen(filename, mode))
#endif

void decrypt(FILE *encrypted_file, FILE *key_file, FILE *decrypted_file)
{
	int encrypted_c;
	int key_c;

	while ((encrypted_c = fgetc(encrypted_file)) != EOF &&
		   (key_c = fgetc(key_file)) != EOF)
	{
		unsigned char decrypted_c =
			(unsigned char)encrypted_c ^ (unsigned char)key_c;

		fputc(decrypted_c, decrypted_file);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <encrypted_file> <key_file>\n", argv[0]);
		return 1;
	}

	FILE *encrypted_file;
	FOPEN(encrypted_file, argv[1], "rb");

	FILE *key_file;
	FOPEN(key_file, argv[2], "rb");

	FILE *decrypted_file;
	FOPEN(decrypted_file, "decrypted.txt", "wb");

	if (!encrypted_file || !key_file || !decrypted_file)
	{
		printf("Error: Failed to open one or more files.\n");
		return 1;
	}

	decrypt(encrypted_file, key_file, decrypted_file);

	fclose(encrypted_file);
	fclose(key_file);
	fclose(decrypted_file);

	printf("Decryption complete.\n");
	return 0;
}
