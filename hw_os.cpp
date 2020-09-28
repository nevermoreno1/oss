#include "types.h"
#include "stat.h"
#include "user.h"

char buf[5120];
int i;
int count;
int cline = 0;
int j = 0;
int k;
int h = 0;
int skip = 0;
int p;
int l;
int m = 1000;
int q = 0;


void
cat(int fd)
{
	int n;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)
	{

		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}


		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcmp(linn[h], linn[h - 1]) == 0)
				{
					skip = 1;
				}
			}
			if (skip == 0)
			{
				printf(1, "%s\n", linn[h]);
			}
			skip = 0;
			j = 0;
			h++;
		}
		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}
	}
	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}





void
uniqq_c(int fd)
{
	int n;
	int countt = 0;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)

	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}

		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcmp(linn[h], linn[h - 1]) != 0)
				{
					skip = 2;
					countt++;
				}
				if (strcmp(linn[h], linn[h - 1]) == 0)
				{
					countt++;
				}
			}
			if (skip == 2)
			{
				printf(1, "%d %s\n", countt, linn[h - 1]);
				countt = 0;
			}

			if ((h == cline - 1) && (strcmp(linn[h], linn[h - 1]) != 0))
			{
				countt = 1;
				printf(1, "%d %s\n", countt, linn[h]);
			}
			if ((h == cline - 1) && (strcmp(linn[h], linn[h - 1]) == 0))
			{
				countt++;
				printf(1, "%d %s\n", countt, linn[h]);
			}

			skip = 0;
			j = 0;
			h++;
		}
		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}

	}
	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}



void
uniqq_d(int fd)
{
	int n;
	int countt = 1;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)
	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}

		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcmp(linn[h], linn[h - 1]) != 0)
				{
					skip = 2;
				}
				if (strcmp(linn[h], linn[h - 1]) == 0)
				{
					if (h == cline - 1)
					{
						skip = 2;
					}
					countt++;

				}
			}
			if (skip == 2 && countt > 1)
			{
				printf(1, "%s\n", linn[h - 1]);
				countt = 1;
			}

			skip = 0;
			j = 0;
			h++;
		}
		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}
	}

	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}



int strcop(char arr[], char ary[], int num)
{
	int i;
	int count = 0;
	int a;
	int b;
	if (strlen(arr) != strlen(ary))
	{
		return -1;
	}
	for (i = 0; i < strlen(arr); i++)
	{
		a = (int)arr[i];
		b = (int)ary[i];

		if ((a == b) || (a - b == 32) || (b - a == 32))
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == num)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}



void
uniqq_i(int fd)
{
	int n;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)
	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}
		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcop(linn[h], linn[h - 1], j) == 0)
				{
					skip = 1;
				}
			}
			if (skip == 0)
			{
				printf(1, "%s\n", linn[h]);
			}
			skip = 0;
			j = 0;
			h++;
		}

		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}
	}
	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}


void
qqq_ll(int fd)
{
	int n;
	int countt = 0;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)

	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}

		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcop(linn[h], linn[h - 1], j) != 0)
				{
					skip = 2;
					countt++;
				}
				if (strcop(linn[h], linn[h - 1], j) == 0)
				{
					countt++;
				}
			}
			if (skip == 2)
			{
				printf(1, "%d %s\n", countt, linn[h - 1]);
				countt = 0;
			}

			if ((h == cline - 1) && (strcop(linn[h], linn[h - 1], j) != 0))
			{
				countt = 1;
				printf(1, "%d %s\n", countt, linn[h]);
			}
			if ((h == cline - 1) && (strcop(linn[h], linn[h - 1], j) == 0))
			{
				countt++;
				printf(1, "%d %s\n", countt, linn[h]);
			}

			skip = 0;
			j = 0;
			h++;
		}
		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}

	}
	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}



void
qqq_mm(int fd)
{
	int n;
	int countt = 1;

	n = read(fd, buf, sizeof(buf));
	count = n;
	if (n > 0)
	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				cline++;
			}
		}

		char** linn;
		linn = malloc(cline * sizeof(char*));
		for (p = 0; p < cline; p++)
		{
			linn[p] = malloc((m + 1) * sizeof(char));
		}
		for (k = 0; k < count; k++)
		{
			while (buf[k] != '\n')
			{
				linn[h][j] = buf[k];
				k++;
				j++;
			}
			if (h > 0)
			{
				if (strcop(linn[h], linn[h - 1], j) != 0)
				{
					skip = 2;
				}
				if (strcop(linn[h], linn[h - 1], j) == 0)
				{
					if (h == cline - 1)
					{
						skip = 2;
					}
					countt++;

				}
			}
			if (skip == 2 && countt > 1)
			{
				printf(1, "%s\n", linn[h - 1]);
				countt = 1;
			}

			skip = 0;
			j = 0;
			h++;
		}

		int v;
		for (v = 0; v < cline; v++)
		{
			free(linn[v]);
		}
	}

	else if (n < 0) {
		printf(1, "cat: read error\n");
		exit();
	}
}





int
main(int argc, char* argv[])
{
	int fd, i;

	/*const char* uniqq=argv[0];*/
	if (argc <= 1) {
		cat(0);
		exit();
	}
	if ((argv[1][0] == '-') && (argv[1][1] == 'c') && (argc == 3) && (argv[1][2] != 'i'))
	{
		fd = open(argv[2], 0);
		uniqq_c(fd);
		close(fd);
		q = 1;
	}
	else if ((argv[1][0] == '-') && (argv[1][1] == 'd') && (argc == 3) && (argv[1][2] != 'i'))
	{
		fd = open(argv[2], 0);
		uniqq_d(fd);
		close(fd);
		q = 1;
	}
	else if ((argv[1][0] == '-') && (argv[1][1] == 'i') && (argc == 3) && (argv[1][2] != 'c') && (argv[1][2] != 'd'))
	{
		fd = open(argv[2], 0);
		uniqq_i(fd);
		close(fd);
		q = 1;
	}

	else if (((argv[1][0] == '-') && (argv[1][1] == 'i') && (argc == 4) && (argv[2][0] == '-') && (argv[2][1] == 'c')) || ((argv[1][0] == '-') && (argv[1][1] == 'c') && (argc == 4) && (argv[2][0] == '-') && (argv[2][1] == 'i')))
	{
		fd = open(argv[3], 0);
		qqq_ll(fd);
		close(fd);
		q = 1;
	}

	else if (((argv[1][0] == '-') && (argv[1][1] == 'i') && (argc == 3) && (argv[1][2] == 'c')) || ((argv[1][0] == '-') && (argv[1][1] == 'c') && (argc == 3) && (argv[1][2] == 'i')))
	{
		fd = open(argv[2], 0);
		qqq_ll(fd);
		close(fd);
		q = 1;
	}

	else if (((argv[1][0] == '-') && (argv[1][1] == 'i') && (argc == 4) && (argv[2][0] == '-') && (argv[2][1] == 'd')) || ((argv[1][0] == '-') && (argv[1][1] == 'd') && (argc == 4) && (argv[2][0] == '-') && (argv[2][1] == 'i')))
	{
		fd = open(argv[3], 0);
		qqq_mm(fd);
		close(fd);
		q = 1;
	}


	else if (((argv[1][0] == '-') && (argv[1][1] == 'i') && (argc == 3) && (argv[1][2] == 'd')) || ((argv[1][0] == '-') && (argv[1][1] == 'd') && (argc == 3) && (argv[1][2] == 'i')))
	{
		fd = open(argv[2], 0);
		qqq_mm(fd);
		close(fd);
		q = 1;
	}


	else if (q == 0)
	{
		for (i = 1; i < argc; i++)
		{
			if ((fd = open(argv[i], 0)) < 0)
			{
				printf(1, "uniqq: cannot open %s\n", argv[i]);
				exit();
			}
			cat(fd);
			close(fd);
		}
	}
	else
	{
		printf(1, "wrong command!");
	}
	exit();
}

