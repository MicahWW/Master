#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void wake_up(int signum) {
	printf("beep beep\nwake up\n");


	// kills process after alarm
	raise(SIGKILL);
}


int main() {
	signal(SIGALRM, wake_up);

	int hour, min, sec, am_or_pm;
	time_t rawtime;
	struct tm * timeinfo;

	// asks for alarm time
	printf("Enter alarm time in format hh mm ss: ");
	scanf("%d%d%d", &hour, &min, &sec);

	printf("Enter 0 for am and 1 for pm: ");
	scanf("%d", &am_or_pm);

	// puts time into military time
	if(am_or_pm == 1) {
		hour += 12;
	}

        // gets the current time
        time(&rawtime);
        timeinfo = localtime(&rawtime);

	int alarm_time_sec = hour*3600 + min*60 + sec;
	int current_time_sec = timeinfo->tm_hour*3600 + timeinfo->tm_min*60 + timeinfo->tm_sec;
	int sec_till_alarm;

	if(alarm_time_sec < current_time_sec) {
		// adds one day
		alarm_time_sec += 86400;
	}

	sec_till_alarm = alarm_time_sec - current_time_sec;

	alarm(sec_till_alarm);



	// runs until the alarm happens
	while(1);
}
