var runas = require("./lib/index");

runas("C:\\Users\\bpasero\\Desktop\\electron\\electron-v1.7.6-win32-x64\\electron.exe", exit => {
    console.log("Exit: " + exit)
});