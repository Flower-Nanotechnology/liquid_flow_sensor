# STM32CubeIDE template project

- Simple GPIO with RTOS template project for STM32CubeIDE without .ioc settings

## How to import

1. Clone the project in your workspace
```bash
git clone https://github.com/Flower-Nanotechnology/liquid_flow_sensor.git
```

2. Import on STM32CubeIDE

- Open STM32CubeIDE
- Create or open an existing workspace
- Go to `File` → `Open Projects from File System...` → `Directory` and find the project folder you just cloned 

3. Rename the project

- In the `Project Explorer` tab, right-click on project's root folder and then click on `Rename` and choose a new name for the project.
- Right-click on the project's root folder again, and now click on `Delete`. `ATENTION: DO NOT select "Delete project contents on disk"!!!`.
- Close STM32CubeIDE
- Open file explorer and go to project's folder. You'll see the project's name remais as before. Rename the project to the same name you just renamed it in STM32CubeIDE
- Open STM32CubeIDE
- Open the project again: Go to `File` → `Open Projects from File System...` → `Directory` and find the project.

4. Build the project

- Right-click on the project's root folder 
- Click on `Clean Project`
- Click on `Build Project`

Now the project is imported and you can code.
