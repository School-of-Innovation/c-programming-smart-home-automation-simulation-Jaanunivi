/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void toggleLight(int rooms, int lights[]);
 void readTemperature(int rooms, int temp[]);
 void detectMotion(int rooms, int motion[]);
 void controlLocks(int rooms, int locks[]);
 void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void checkAutoLock(int rooms, int motion[], int locks[], int *noMotionCount);
 void checkTemperatureAlert(int rooms, int temp[]);
 void checkEnergySavingMode(int rooms, int lights[], int *allLightsOnCount);
 
 int main() {
     int rooms;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
     
     int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
     initializeSystem(rooms, lights, temp, motion, locks);
     
     int choice, noMotionCount = 0, allLightsOnCount = 0;
     
     do {
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n");
         printf("2. Read Temperature\n");
         printf("3. Check Motion Sensor\n");
         printf("4. Lock/Unlock Security System\n");
         printf("5. House Status Summary\n");
         printf("6. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1:
                 toggleLight(rooms, lights);
                 checkEnergySavingMode(rooms, lights, &allLightsOnCount);
                 break;
             case 2:
                 readTemperature(rooms, temp);
                 checkTemperatureAlert(rooms, temp);
                 break;
             case 3:
                 detectMotion(rooms, motion);
                 checkAutoLock(rooms, motion, locks, &noMotionCount);
                 break;
             case 4:
                 controlLocks(rooms, locks);
                 break;
             case 5:
                 houseStatus(rooms, lights, temp, motion, locks);
                 break;
             case 6:
                 printf("Exiting...\n");
                 break;
             default:
                 printf("Invalid choice!\n");
         }
     } while (choice != 6);
     
     return 0;
 }
 
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;
         temp[i] = 22 + (i % 5);
         motion[i] = 0;
         locks[i] = 1;
     }
     printf("System initialized.\n");
 }
 
 void toggleLight(int rooms, int lights[]) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         lights[room - 1] = !lights[room - 1];
         printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void readTemperature(int rooms, int temp[]) {
     int room;
     printf("Enter room number to read temperature (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Room %d Temperature: %d°C\n", room, temp[room - 1]);
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void detectMotion(int rooms, int motion[]) {
     for (int i = 0; i < rooms; i++) {
         motion[i] = rand() % 2;
     }
     printf("Motion sensors updated.\n");
 }
 
 void controlLocks(int rooms, int locks[]) {
     int room;
     printf("Enter room number to lock/unlock (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         locks[room - 1] = !locks[room - 1];
         printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
                lights[i] ? "ON" : "OFF", temp[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
 
 void checkAutoLock(int rooms, int motion[], int locks[], int *noMotionCount) {
     int noMotion = 1;
     for (int i = 0; i < rooms; i++) {
         if (motion[i]) {
             noMotion = 0;
             *noMotionCount = 0;
             break;
         }
     }
     if (noMotion) {
         (*noMotionCount)++;
         if (*noMotionCount >= 5) {
             for (int i = 0; i < rooms; i++) {
                 locks[i] = 1;
             }
             printf("Auto-Lock activated: All doors locked due to inactivity.\n");
             *noMotionCount = 0;
         }
     }
 }
 
 void checkTemperatureAlert(int rooms, int temp[]) {
     for (int i = 0; i < rooms; i++) {
         if (temp[i] > 30) {
             printf("Warning: Room %d temperature exceeded 30°C!\n", i + 1);
         }
     }
 }
 
 void checkEnergySavingMode(int rooms, int lights[], int *allLightsOnCount) {
     int allOn = 1;
     for (int i = 0; i < rooms; i++) {
         if (!lights[i]) {
             allOn = 0;
             *allLightsOnCount = 0;
             break;
         }
     }
     if (allOn) {
         (*allLightsOnCount)++;
         if (*allLightsOnCount >= 5) {
             printf("Energy Saving Mode: All lights have been ON for too long. Consider turning them off.\n");
             *allLightsOnCount = 0;
         }
     }
 }
 