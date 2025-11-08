# trims automodinstaller

Trim's Auto Mod Installer

Use a GitHub Gist or any URL that has a json format that includes:

"modID" (set as 0 for first mod, 1 for second and so on) - used for download tracker and status update
"name" (name of the mod) - used for mod list
"description" (description of the mod) - used for mod list
"cdn_url" (preferably Modrinth) - used to install the mod
Insert the URL into the slot and choose the folder to install the mods to and click Install. thats it.

Example:

{
"modID": 0,
"name": "Mod Name",
"description": "Mod Description",
"cdn_url": "https://cdn.modrinth.com/data/...
}

You can get the CDN from Modrinth by right clicking on the download button (once you have chosen the version and loader) and clicking Copy link/URL address.
