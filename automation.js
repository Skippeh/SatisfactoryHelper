"use strict";

const fs = require("fs");
const path = require("path");

if (process.argv.length < 3) {
    console.error("Usage: node automation.js <ModLoaderRootPath> <Build Configuration> [...ModList]");
    process.exit(1);
}

const ModLoaderRootPath = process.argv[2];
const BuildConfiguration = process.argv[3];
const ModList = process.argv.slice(4);

if (!fs.existsSync(`${ModLoaderRootPath}/GamePath.txt`)) {
    console.error(`GamePath.txt does not exist in ${ModLoaderRootPath}.`);
    process.exit(1);
}

const SatisfactoryPaths = fs.readFileSync(`${ModLoaderRootPath}/GamePath.txt`, "utf-8").replace("\r", "").split("\n");

console.log(`Build Configuration: ${BuildConfiguration} SF Root: ${SatisfactoryPaths.join(", ")} ModLoader Root: ${ModLoaderRootPath} Mod List: ${ModList.join(", ")}`);

if (BuildConfiguration != "Shipping") {
    console.info("Skipping copying mod DLLs, build configuration != Shipping");
    process.exit(0);
}

function CopyFileAndLog(SourceFilePath, DestinationFolder) {
    if (fs.existsSync(SourceFilePath)) {
        let DestinationFile = `${DestinationFolder}/${path.basename(SourceFilePath)}`;
        try {
            fs.copyFileSync(SourceFilePath, DestinationFile);
            console.info(`${SourceFilePath} -> ${DestinationFile}`);
            return true;
        } catch (e) {
            console.error(`Failed to copy file ${SourceFilePath} to ${DestinationFolder}: ${e.message}`);
        }
    }
    else {
        console.error(`Source file not found: ${SourceFilePath}`);
    }

    return false;
}

let ModsCopied = 0;

for (let ModId of ModList) {
    console.info(`Copying mod: ${ModId}...`);

    const FolderName = `FactoryGame/Mods/${ModId}/Binaries/Win64`;
    const SourceFilePathBase = `${ModLoaderRootPath}/Plugins/${ModId}/Binaries/Win64/UE4-${ModId}-Win64-Shipping`;

    for (const SatisfactoryPath of SatisfactoryPaths) {
        const DestinationFolder = `${SatisfactoryPath}/${FolderName}`;

        if (CopyFileAndLog(`${SourceFilePathBase}.dll`, DestinationFolder)) {
            CopyFileAndLog(`${SourceFilePathBase}.pdb`, DestinationFolder);
        }
    }

    ModsCopied++;
}

console.log(`Done. Copied ${ModsCopied} mod(s).`);

if (ModsCopied !== ModList.length) {
    process.exit(1);
}