# SQLite 

Here is a tutorial for using SQLite with the C language.

SQLite is famous for its great feature zero-configuration, which means no complex setup or administration is needed. This chapter will take you through the process of setting up SQLite on Windows, Linux and Mac OS X.

Install SQLite on Windows
Step 1 − Go to SQLite download page (https://www.sqlite.org/download.html), and download precompiled binaries from Windows section.

Step 2 − Download sqlite-shell-win32-*.zip and sqlite-dll-win32-*.zip zipped files.

Step 3 − Create a folder C:\>sqlite and unzip above two zipped files in this folder, which will give you sqlite3.def, sqlite3.dll and sqlite3.exe files.

Step 4 − Add C:\>sqlite in your PATH environment variable and finally go to the command prompt and issue sqlite3 command, which should display the following result: 

  SQLite version 3.38.5 2022-05-06 15:25:27
  Enter ".help" for usage hints.
  Connected to a transient in-memory database.
  Use ".open FILENAME" to reopen on a persistent database.
  sqlite>

From: https://www.tutorialspoint.com/sqlite/sqlite_installation.htm.

ATTENTION: If you are using Dev-C++ on Windows, create a "Project" as "Console Application" and check the "C Project" option. Then add to the project (from sqlite-amalgamation-3380500.zip) the "sqlite3.c", "sqlite3.h" and "sqlite3ext.h" files. WITHOUT IT DONE, NOTHING WILL WORK!
