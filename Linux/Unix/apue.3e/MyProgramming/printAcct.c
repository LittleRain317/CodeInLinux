#include "../include/apue.h"
#include <sys/acct.h>

static unsigned long 
compt2ulong(comp_t comptime)
{
	return (comptime & 0x1fff) << (((comptime >> 13) & 0x7) * 3);
}

int main(int argc, char *argv[])
{
	struct acct_v3 acdata;
	FILE *fp;
	if (argc != 2)
		err_quit("usage: pracct filename");
	if ((fp = fopen(argv[1]	, "r")) == NULL)
		err_sys("can't open %s", argv[1]);
	while (fread(&acdata, sizeof(acdata), 1, fp) == 1)
	{
		printf("acct_v3.ac_flag = %c %c %c %c\n"
			   "acct_v3.ac_version = %d\n"
			   "acct_v3.ac_tty = %u\n"
			   "acct_v3.ac_exitcode = %u\n"
			   "acct_v3.ac_uid = %u\n"
				"acct_v3.ac_gid = %u\n"
				"acct_v3.ac_pid = %u\n"
				"acct_v3.ac_ppid = %u\n"
				"acct_v3.ac_btime = %u\n"
				"acct_v3.ac_etime = %.2f\n"
				"acct_v3.ac_utime = %lu\n"
				"acct_v3.ac_stime = %lu\n"
				"acct_v3.ac_mem = %lu\n"
				"acct_v3.ac_io  = %lu\n"
				"acct_v3.ac_rw   = %lu\n"
				"acct_v3.ac_minflt = %lu\n" 
				"acct_v3.ac_majflt = %lu\n" 
				"acct_v3.ac_swaps = %lu\n"
				"acct_v3.ac_comm = %s\n\n\n\n"
			   ,
				acdata.ac_flag & ACORE ? 'D' : ' ',
				acdata.ac_flag & AXSIG ? 'X' : ' ',
				acdata.ac_flag & AFORK ? 'F' : ' ',
				acdata.ac_flag & ASU   ? 'S' : ' ',
				acdata.ac_version,
                acdata.ac_tty,
                acdata.ac_exitcode,
                acdata.ac_uid,
                acdata.ac_gid,
                acdata.ac_pid,
                acdata.ac_ppid,
                acdata.ac_btime,
                acdata.ac_etime,
                compt2ulong(acdata.ac_utime),
                compt2ulong(acdata.ac_stime),
                compt2ulong(acdata.ac_mem),
                compt2ulong(acdata.ac_io),
                compt2ulong(acdata.ac_rw),
                compt2ulong(acdata.ac_minflt),
                compt2ulong(acdata.ac_majflt),
                compt2ulong(acdata.ac_swaps),
                acdata.ac_comm );
	}
	if (ferror(fp))
	{
		err_sys("read error");
	}
	return 0;
}
