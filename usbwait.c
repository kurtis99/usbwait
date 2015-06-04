#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

const char *argp_program_version = "argp-ex3 1.0";
const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] = "Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "ARG1 ARG2";

/* The options we understand. */
static struct argp_option options[] = {
    {"verbose",  'V', NULL,      0,  "Produce verbose output", 0 },
    {"quiet",    'q', NULL,      0,  "Don't produce any output", 0 },
    {"silent",   's', NULL,      0, NULL, 0 },

    {"pid", 'p', "PID", 0, "Output to PID instead of standard output", 0},
    {"vid", 'v', "VID", 0, "Output to VID instead of standard output", 0},

    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
	int vid, pid;
	int silent, verbose;
};

/* Parse a single option. */
static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
/* Get the input argument from argp_parse, which we
*      know is a pointer to our arguments structure. */
	struct arguments *arguments = state->input;

	switch (key) {
	case 'q':
	case 's':
		arguments->silent = 1;
		break;
	case 'V':
		arguments->verbose = 1;
		break;
	case 'v':
		arguments->vid = strtol(arg, NULL, 16);
		break;
	case 'p':
		arguments->pid = strtol(arg, NULL, 16);
		break;

	default:
		return ARGP_ERR_UNKNOWN;
	}

	return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc, NULL, NULL, NULL };

int main (int argc, char **argv)
{
	struct arguments arguments;

	/* Default values. */
	arguments.silent = 0;
	arguments.verbose = 0;
	arguments.vid = 0x0;
	arguments.pid = 0x0;

	/* Parse our arguments; every option seen by parse_opt will
	*      be reflected in arguments. */
	argp_parse (&argp, argc, argv, 0, 0, &arguments);

	printf ("VID = 0x%04X\nPID = 0x%04X\nVERBOSE = %s\nSILENT = %s\n",
		arguments.vid, arguments.pid,
		arguments.verbose ? "yes" : "no",
		arguments.silent ? "yes" : "no");

	return 0;
}






