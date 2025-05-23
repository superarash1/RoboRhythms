# RoboRhythms
This is the repository for SBRT RoboRhythms event used to program an ESP-32 to play music with a buzzer

# Setup Instructions
Step 1: Download and run Arduino IDE <br /> 
- Download Page: https://www.arduino.cc/en/software/ <br /> 

Step 2: Open Preferences window<br /> 
- Look in the top left corner of the Arduino IDE window<br /> 
- Then select the following: Files > Preferences<br /> 

Step 3: Paste URL into boards manager<br /> 
- Find the "Additional boards manager URLs: " at the bottom of the preferences menu<br /> 
- Paste the following link into the text field: https://dl.espressif.com/dl/package_esp32_index.json<br /> 
- Press Ok and exit the preferences menu <br /> 

Step 4: Install esp32 by Espressif<br /> 
- Now navigate to Tools > Board: "XXXXXXX" > Boards Manager...<br /> 
- A side bar will appear on the left<br /> 
- Type in "esp32" into the search bar and click install on the one that specifically says "esp32 by Espressif" <br /> 

Step 5: Select Board<br /> 
- Navigate to Tools > Board: "XXXXXXX" > esp32 and click on the one that says "ESP32 Dev Module"<br /> 

Step 6: Get Files into Arduino Folder<br /> 
- Option 1: Clone Repository into Arduino Folder <br /> 
  - Install Git if you haven't already: https://git-scm.com/book/en/v2/Getting-Started-Installing-Git <br /> 
  - Open your File Explorer and navigate to Documents > Arduino<br /> 
  - Right click on the window and select "Open in Terminal" <br /> 
  - Paste the following into the terminal and hit enter: "git clone https://github.com/superarash1/RoboRhythms.git" <br /> 

- Option 2: Directly Download Files and Paste into Arduino Folder<br /> 
  - First scroll up and click on the bright green button that says "<> Code"<br /> 
  - Click on "Download ZIP"<br />
  - Go to your downloads folder, extract the zip file, select the files inside, and press ctrl + c <br />
  - Navigate to Documents > Arduino <br />
  - Paste the files into the folder <br />

Step 7: Install ESP32 Drivers 
- Download the driver installer from the link. It should be called "CP210x Windows Drivers" : https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads
- Extract the zip file and run the .exe file inside

Step 8: Open Files in Arduino IDE from the side bar on the left
- Select the file icon on the left side bar, below the blue circle checkmark button
- Then click on the RoboRhythms Folder and open the files
