# SatisfactoryHelper

A Quality of Life mod for Satisfactory that adds:
* Ability to show all recipes and items in-game, including the ability to see where each item is used or can be used.

## Getting started

### Dependencies
- You need a custom version of Unreal Engine to develop and package the mod. It can be downloaded here: https://github.com/SatisfactoryModdingUE/UnrealEngine/releases
  - Note that you need to register your GitHub account at Epic Games to get access. It can be done here: https://www.unrealengine.com/en-US/ue4-on-github
- Install Wwise version ```2019.1.7.7135```.
  - Instructions can be found here: https://docs.ficsit.app/satisfactory-modding/2.1.0/Development/BeginnersGuide/dependencies.html
- For playtesting you need to install the Satisfactory Mod Manager so the game will load the mod.
  - It can be downloaded here: https://github.com/satisfactorymodding/SatisfactoryModLauncher/releases
- Visual Studio 2017 with C++ desktop and game development modules added. It does not work well with Visual Studio 2019 in my experience but if you get it to work then be my guest.
  - VS2017 can be downloaded here: https://visualstudio.microsoft.com/vs/older-downloads/

### Project setup
**I highly recommend putting the project on an SSD if possible to decrease compilation/linking times**
1. First of all you need to generate the Wwise project and install the Wwise plugin to the project. Instructions on how to do this can be found here: https://docs.ficsit.app/satisfactory-modding/2.1.0/Development/BeginnersGuide/project_setup.html
2. Make sure you've launched the custom version of Unreal Engine that you installed above. It can most likely be found in the start menu as ```Unreal Engine - CSS``` (CSS stands for Coffee Stain Studios).
3. Right click FactoryGame.uproject and click ```Switch Unreal Engine Version...```, select ```4.22.3-CSS``` in the dropdown list. If you can't find it you can add it manually using the ```...``` button. Browse to the CSS version of Unreal Engine that you installed earlier.
4. Right click the FactoryGame.uproject in the root of the repository and click ```Generate Visual Studio project files```.
5. Open the generated .sln file with Visual Studio and compile both ```Development Editor``` and ```Shipping``` configurations selected. You can do a batch build (found under ```Build > Batch Build...``` in the window toolbar) to do both of them after eachother automatically. This will take some time.
6. Open FactoryGame.uproject. Make sure the selected unreal engine is still ```4.22.3-CSS```.
7. Compile the modules if the question appears.
8. Now you're ready to start developing.

### Playtesting/cooking mod
1. In the unreal editor click the Alpakit button in the top middle.
2. Configure the path to the game and check the ```Copy Mods to Game``` checkbox. Check the ```Start Game``` checkbox if you want to launch the game after it's done cooking the mod.
3. Add an array element to the Mods array.
4. Set the name of the mod to ```SatisfactoryHelper``` and fill the rest of the fields with appropriate values (nothing is enforced except the Name field as it needs to match the folder name of the mod under ```Content/```).
5. Open the ```Binaries/Win64``` folder and copy ```UE4-SatisfactoryHelper-Win64-Shipping.dll``` to the game's ```mods``` folder. Optionally also copy the symbols (.pdb) file if you need debugging symbols for troubleshooting crashes.
   - NOTE: Make sure the shipping build is up to date in Visual Studio.
     - Tip: If you're doing changes to code that's only executed in-game you don't need to compile the ```Development Editor``` configuration as well to save time. This does not include changes to headers however (that the engine is aware of by the use of UCLASS/UPROPERTY etc). Just build the ```Shipping``` configuration in Visual Studio and copy the .dll to the game's ```mods``` folder and launch the game normally.
6. Click the ```Alpakit!``` button when you're ready to build.

### Common errors
Here are some common errors and solutions/workarounds i've come across:
- Sometimes if the editor crashes for whatever reason, when the project is reopened again a message will pop up saying the Alpakit plugin is not compiled properly or something like that.
  - To fix this browse to Plugins/Alpakit and delete the following folders: ```Binaries```, ```Intermediate```. Compile the project in Visual Studio with the ```Development Editor``` configuration and then try launching the editor again.
- Visual Studio gets confused by UE4 so intellisense is pretty broken and the error window will sometimes have false positives.
  - I recommend following this guide to configure VS: https://docs.unrealengine.com/en-US/Programming/Development/VisualStudioSetup/index.html (specifically the ```Turn Off the Error List Window``` and ```Increase the Width of Solution Configurations Dropdown Menu``` sections).
  - If possible install and use Visual Assist X for better intellisense.
- Sometimes the game will take around a minute to launch then crash, and Epic Games Launcher will come up saying the game is already running.
  - Open the task manager and check if CrashReporter.exe from the game is running and terminate it. Relaunch the game using ```FactoryGame.exe```.
    - Most of the time it won't be running and EGS is just being weird (or it terminated already). Relaunching the game works in this case.
