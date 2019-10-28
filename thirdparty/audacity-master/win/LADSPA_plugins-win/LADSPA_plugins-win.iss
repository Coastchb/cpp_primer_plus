; LADSPA_plugins-win Installer
; Vaughan Johnson, September 2006
; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=LADSPA_plugins-win
AppVerName=LADSPA_plugins-win-0.4.15
AppPublisher=Audacity Team
AppPublisherURL=http://www.audacityteam.org
AppSupportURL=http://www.audacityteam.org
AppUpdatesURL=http://www.audacityteam.org
DefaultDirName={pf}\Audacity\Plug-Ins
; Don't do the dir exists warning. We want it to already exist.
DirExistsWarning=no
DefaultGroupName=LADSPA_plugins-win
DisableProgramGroupPage=yes
LicenseFile=..\..\LICENSE.txt
InfoBeforeFile=readme_LADSPA_plugins-win.txt
OutputDir=.\Installer
OutputBaseFilename=LADSPA_plugins-win-0.4.15
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "basque"; MessagesFile: "compiler:Languages\Basque.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"
Name: "catalan"; MessagesFile: "compiler:Languages\Catalan.isl"
Name: "czech"; MessagesFile: "compiler:Languages\Czech.isl"
Name: "danish"; MessagesFile: "compiler:Languages\Danish.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "finnish"; MessagesFile: "compiler:Languages\Finnish.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "german"; MessagesFile: "compiler:Languages\German.isl"
Name: "hungarian"; MessagesFile: "compiler:Languages\Hungarian.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "norwegian"; MessagesFile: "compiler:Languages\Norwegian.isl"
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"
Name: "portuguese"; MessagesFile: "compiler:Languages\Portuguese.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "slovak"; MessagesFile: "compiler:Languages\Slovak.isl"
Name: "slovenian"; MessagesFile: "compiler:Languages\Slovenian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Files]
; Note that {app} is the plugins directory.
Source: "readme_LADSPA_plugins-win.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\Release\*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\Release\FFTW_docs\*"; DestDir: "{app}\FFTW_docs"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
