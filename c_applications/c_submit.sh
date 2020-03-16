universe = vanilla
executable = estimate_pi.exe
arguments = $(PROCESS) 10000
transfer_output_files = output$(PROCESS).txt
should_transfer_files = YES
when_to_transfer_output = ON_EXIT
request_cpus = 1
requirements = (Arch=="X86_64") && (OpSys=="WINDOWS")
output = logs/stdout.log
error = logs/stderr.log
log = logs/log.log
notification = never
queue 10