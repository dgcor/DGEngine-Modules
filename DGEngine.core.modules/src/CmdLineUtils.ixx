export module dgengine.cmdlineutils;

export namespace CmdLineUtils
{
	// returns true if any export command was found (reagrdless of success)
	bool processCmdLine(int argc, const char* argv[]);
}
