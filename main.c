#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

int main(int ac, char **av)
{
	if (ac == 1)
		printf("{"
			   "\"amount\":\"%d\","
			   "\"available\":\"%d\""
			   "}",
			   get_nprocs_conf(),
			   get_nprocs());
	else if (ac == 2 && 0 == memcmp("amount", av[1], strlen(av[1])))
		printf("%d", get_nprocs_conf());
	else if (ac == 2 && 0 == memcmp("avaiable", av[1], strlen(av[1])))
		printf("%d", get_nprocs());
	else
		return (1);
	return (0);
}