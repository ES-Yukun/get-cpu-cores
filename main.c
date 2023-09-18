#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

int main(int ac, char **av)
{
	int av1_len;

	if (ac == 2)
		av1_len = strlen(av[1]) + 1;
	if (ac == 1)
		printf("{"
			   "\"all\":\"%d\","
			   "\"enabled\":\"%d\""
			   "}",
			   get_nprocs_conf(),
			   get_nprocs());
	else if (ac == 2 &&
			 (0 == memcmp("--all", av[1], av1_len) ||
			  0 == memcmp("-a", av[1], av1_len)))
		printf("%d", get_nprocs_conf());
	else if (ac == 2 &&
			 (0 == memcmp("--enabled", av[1], av1_len) ||
			  0 == memcmp("-e", av[1], av1_len)))
		printf("%d", get_nprocs());
	else if (ac == 2 && 0 == memcmp("--help", av[1], av1_len))
		printf("Usage: getcpu [OPTION...]\n"
		"\n"
		"  --all, -a\t\tprint amount cpu cores\n"
		"  --enabled, -e\t\tprint enabled cpu cores\n");
	else
		return (1);
	return (0);
}