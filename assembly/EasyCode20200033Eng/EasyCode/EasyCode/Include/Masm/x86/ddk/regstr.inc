;===================================================================;
;                                                                   ;
;   regstr.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF REGSTR_INC
REGSTR_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

REGSTR_KEY_CLASS                                            Equ         TEXT("Class")
REGSTR_KEY_CONFIG                                           Equ         TEXT("Config")
REGSTR_KEY_ENUM                                             Equ         TEXT("Enum")
REGSTR_KEY_ROOTENUM                                         Equ         TEXT("Root")
REGSTR_KEY_BIOSENUM                                         Equ         TEXT("BIOS")
REGSTR_KEY_ACPIENUM                                         Equ         TEXT("ACPI")
REGSTR_KEY_PCMCIAENUM                                       Equ         TEXT("PCMCIA")
REGSTR_KEY_PCIENUM                                          Equ         TEXT("PCI")
REGSTR_KEY_VPOWERDENUM                                      Equ         TEXT("VPOWERD")
IFNDEF NEC_98
    REGSTR_KEY_ISAENUM                                      Equ         TEXT("ISAPnP")
    REGSTR_KEY_EISAENUM                                     Equ         TEXT("EISA")
ELSE
    REGSTR_KEY_ISAENUM                                      Equ         TEXT("C98PnP")
    REGSTR_KEY_EISAENUM                                     Equ         TEXT("NESA")
ENDIF
REGSTR_KEY_LOGCONFIG                                        Equ         TEXT("LogConfig")
REGSTR_KEY_SYSTEMBOARD                                      Equ         TEXT("*PNP0C01")
REGSTR_KEY_APM                                              Equ         TEXT("*PNP0C05")

REGSTR_KEY_INIUPDATE                                        Equ         TEXT("IniUpdate")
REG_KEY_INSTDEV                                             Equ         TEXT("Installed")

REGSTR_KEY_DOSOPTCDROM                                      Equ         TEXT("CD-ROM")
REGSTR_KEY_DOSOPTMOUSE                                      Equ         TEXT("MOUSE")

REGSTR_KEY_KNOWNDOCKINGSTATES                               Equ         TEXT("Hardware Profiles")
REGSTR_KEY_DEVICEPARAMETERS                                 Equ         TEXT("Device Parameters")

REGSTR_DEFAULT_INSTANCE                                     Equ         TEXT("0000")
REGSTR_PATH_MOTHERBOARD                                     Equ         TEXT("*PNP0C01\0000")
REGSTR_PATH_SETUP                                           Equ         TEXT("Software\Microsoft\Windows\CurrentVersion")
REGSTR_PATH_DRIVERSIGN                                      Equ         TEXT("Software\Microsoft\Driver Signing")
REGSTR_PATH_NONDRIVERSIGN                                   Equ         TEXT("Software\Microsoft\Non-Driver Signing")
REGSTR_PATH_DRIVERSIGN_POLICY                               Equ         TEXT("Software\Policies\Microsoft\Windows NT\Driver Signing")
REGSTR_PATH_NONDRIVERSIGN_POLICY                            Equ         TEXT("Software\Policies\Microsoft\Windows NT\Non-Driver Signing")
REGSTR_PATH_PIFCONVERT                                      Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\PIFConvert")
REGSTR_PATH_MSDOSOPTS                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\MS-DOSOptions")
REGSTR_PATH_NOSUGGMSDOS                                     Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\NoMSDOSWarn")
REGSTR_PATH_NEWDOSBOX                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\MS-DOSSpecialConfig")
REGSTR_PATH_RUNONCE                                         Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\RunOnce")
REGSTR_PATH_RUNONCEEX                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\RunOnceEx")
REGSTR_PATH_RUN                                             Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Run")
REGSTR_PATH_RUNSERVICESONCE                                 Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\RunServicesOnce")
REGSTR_PATH_RUNSERVICES                                     Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\RunServices")
REGSTR_PATH_EXPLORER                                        Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer")
REGSTR_PATH_PROPERTYSYSTEM                                  Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\PropertySystem")
REGSTR_PATH_DETECT                                          Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Detect")
REGSTR_PATH_APPPATHS                                        Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\App Paths")
REGSTR_PATH_UNINSTALL                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Uninstall")
REGSTR_PATH_REALMODENET                                     Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Network\Real Mode Net")
REGSTR_PATH_NETEQUIV                                        Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Network\Equivalent")
REGSTR_PATH_CVNETWORK                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Network")
REGSTR_PATH_WMI_SECURITY                                    Equ         TEXT("System\CurrentControlSet\Control\Wmi\Security")
REGSTR_PATH_RELIABILITY                                     Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Reliability")
REGSTR_PATH_RELIABILITY_POLICY                              Equ         TEXT("Software\Policies\Microsoft\Windows NT\Reliability")
REGSTR_PATH_RELIABILITY_POLICY_SHUTDOWNREASONUI             Equ         TEXT("ShutdownReasonUI")
REGSTR_PATH_RELIABILITY_POLICY_SNAPSHOT                     Equ         TEXT("Snapshot")
REGSTR_PATH_RELIABILITY_POLICY_REPORTSNAPSHOT               Equ         TEXT("ReportSnapshot")

REGSTR_PATH_REINSTALL                                       Equ         TEXT("SOFTWARE\Microsoft\Windows\CurrentVersion\Reinstall")
REGSTR_PATH_NT_CURRENTVERSION                               Equ         TEXT("Software\Microsoft\Windows NT\CurrentVersion")

REGSTR_PATH_VOLUMECACHE                                     Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer\VolumeCaches")
REGSTR_VAL_DISPLAY                                          Equ         TEXT("display")

REGSTR_PATH_IDCONFIGDB                                      Equ         TEXT("System\CurrentControlSet\Control\IDConfigDB")
REGSTR_PATH_CRITICALDEVICEDATABASE                          Equ         TEXT("System\CurrentControlSet\Control\CriticalDeviceDatabase")
REGSTR_PATH_CLASS                                           Equ         TEXT("System\CurrentControlSet\Services\Class")
REGSTR_PATH_DISPLAYSETTINGS                                 Equ         TEXT("Display\Settings")
REGSTR_PATH_FONTS                                           Equ         TEXT("Display\Fonts")
REGSTR_PATH_ENUM                                            Equ         TEXT("Enum")
REGSTR_PATH_ROOT                                            Equ         TEXT("Enum\Root")

REGSTR_PATH_CURRENTCONTROLSET                               Equ         TEXT("System\CurrentControlSet")
REGSTR_PATH_SYSTEMENUM                                      Equ         TEXT("System\CurrentControlSet\Enum")
REGSTR_PATH_HWPROFILES                                      Equ         TEXT("System\CurrentControlSet\Hardware Profiles")
REGSTR_PATH_HWPROFILESCURRENT                               Equ         TEXT("System\CurrentControlSet\Hardware Profiles\Current")
REGSTR_PATH_CLASS_NT                                        Equ         TEXT("System\CurrentControlSet\Control\Class")
REGSTR_PATH_PER_HW_ID_STORAGE                               Equ         TEXT("Software\Microsoft\Windows NT\CurrentVersion\PerHwIdStorage")

REGSTR_PATH_DEVICE_CLASSES                                  Equ         TEXT("System\CurrentControlSet\Control\DeviceClasses")

REGSTR_PATH_CODEVICEINSTALLERS                              Equ         TEXT("System\CurrentControlSet\Control\CoDeviceInstallers")
REGSTR_PATH_BUSINFORMATION                                  Equ         TEXT("System\CurrentControlSet\Control\PnP\BusInformation")

REGSTR_PATH_SERVICES                                        Equ         TEXT("System\CurrentControlSet\Services")
REGSTR_PATH_VXD                                             Equ         TEXT("System\CurrentControlSet\Services\VxD")
REGSTR_PATH_IOS                                             Equ         TEXT("System\CurrentControlSet\Services\VxD\IOS")
REGSTR_PATH_VMM                                             Equ         TEXT("System\CurrentControlSet\Services\VxD\VMM")
REGSTR_PATH_VPOWERD                                         Equ         TEXT("System\CurrentControlSet\Services\VxD\VPOWERD")
REGSTR_PATH_VNETSUP                                         Equ         TEXT("System\CurrentControlSet\Services\VxD\VNETSUP")
REGSTR_PATH_NWREDIR                                         Equ         TEXT("System\CurrentControlSet\Services\VxD\NWREDIR")
REGSTR_PATH_NCPSERVER                                       Equ         TEXT("System\CurrentControlSet\Services\NcpServer\Parameters")
REGSTR_PATH_VCOMM                                           Equ         TEXT("System\CurrentControlSet\Services\VxD\VCOMM")

REGSTR_PATH_IOARB                                           Equ         TEXT("System\CurrentControlSet\Services\Arbitrators\IOArb")
REGSTR_PATH_ADDRARB                                         Equ         TEXT("System\CurrentControlSet\Services\Arbitrators\AddrArb")
REGSTR_PATH_DMAARB                                          Equ         TEXT("System\CurrentControlSet\Services\Arbitrators\DMAArb")
REGSTR_PATH_IRQARB                                          Equ         TEXT("System\CurrentControlSet\Services\Arbitrators\IRQArb")

REGSTR_PATH_CODEPAGE                                        Equ         TEXT("System\CurrentControlSet\Control\Nls\Codepage")
REGSTR_PATH_FILESYSTEM                                      Equ         TEXT("System\CurrentControlSet\Control\FileSystem")
REGSTR_PATH_FILESYSTEM_NOVOLTRACK                           Equ         TEXT("System\CurrentControlSet\Control\FileSystem\NoVolTrack")
REGSTR_PATH_CDFS                                            Equ         TEXT("System\CurrentControlSet\Control\FileSystem\CDFS")
REGSTR_PATH_WINBOOT                                         Equ         TEXT("System\CurrentControlSet\Control\WinBoot")
REGSTR_PATH_INSTALLEDFILES                                  Equ         TEXT("System\CurrentControlSet\Control\InstalledFiles")
REGSTR_PATH_VMM32FILES                                      Equ         TEXT("System\CurrentControlSet\Control\VMM32Files")

REGSTR_MAX_VALUE_LENGTH                                     Equ         256

REGSTR_KEY_DEVICE_PROPERTIES                                Equ         TEXT("Properties")
REGSTR_VAL_SLOTNUMBER                                       Equ         TEXT("SlotNumber")
REGSTR_VAL_ATTACHEDCOMPONENTS                               Equ         TEXT("AttachedComponents")
REGSTR_VAL_BASEDEVICEPATH                                   Equ         TEXT("BaseDevicePath")
REGSTR_VAL_SYSTEMBUSNUMBER                                  Equ         TEXT("SystemBusNumber")
REGSTR_VAL_BUSDATATYPE                                      Equ         TEXT("BusDataType")
REGSTR_VAL_INTERFACETYPE                                    Equ         TEXT("InterfaceType")
REGSTR_VAL_SERVICE                                          Equ         TEXT("Service")
REGSTR_VAL_DETECTSIGNATURE                                  Equ         TEXT("DetectSignature")
REGSTR_VAL_CLASSGUID                                        Equ         TEXT("ClassGUID")
REGSTR_VAL_INSTANCEIDENTIFIER                               Equ         TEXT("InstanceIdentifier")
REGSTR_VAL_DUPLICATEOF                                      Equ         TEXT("DuplicateOf")
REGSTR_VAL_STATUSFLAGS                                      Equ         TEXT("StatusFlags")
REGSTR_VAL_DISABLECOUNT                                     Equ         TEXT("DisableCount")
REGSTR_VAL_UNKNOWNPROBLEMS                                  Equ         TEXT("UnknownProblem")
REGSTR_VAL_DOCKSTATE                                        Equ         TEXT("DockState")
REGSTR_VAL_PREFERENCEORDER                                  Equ         TEXT("PreferenceOrder")
REGSTR_VAL_USERWAITINTERVAL                                 Equ         TEXT("UserWaitInterval")
REGSTR_VAL_DEVICE_INSTANCE                                  Equ         TEXT("DeviceInstance")
REGSTR_VAL_SYMBOLIC_LINK                                    Equ         TEXT("SymbolicLink")
REGSTR_VAL_DEFAULT                                          Equ         TEXT("Default")
REGSTR_VAL_LOWERFILTERS                                     Equ         TEXT("LowerFilters")
REGSTR_VAL_UPPERFILTERS                                     Equ         TEXT("UpperFilters")
REGSTR_VAL_LOCATION_INFORMATION                             Equ         TEXT("LocationInformation")
REGSTR_VAL_UI_NUMBER                                        Equ         TEXT("UINumber")
REGSTR_VAL_UI_NUMBER_DESC_FORMAT                            Equ         TEXT("UINumberDescFormat")
REGSTR_VAL_CAPABILITIES                                     Equ         TEXT("Capabilities")
REGSTR_VAL_DEVICE_TYPE                                      Equ         TEXT("DeviceType")
REGSTR_VAL_DEVICE_CHARACTERISTICS                           Equ         TEXT("DeviceCharacteristics")
REGSTR_VAL_DEVICE_SECURITY_DESCRIPTOR                       Equ         TEXT("Security")
REGSTR_VAL_DEVICE_EXCLUSIVE                                 Equ         TEXT("Exclusive")
REGSTR_VAL_RESOURCE_PICKER_TAGS                             Equ         TEXT("ResourcePickerTags")
REGSTR_VAL_RESOURCE_PICKER_EXCEPTIONS                       Equ         TEXT("ResourcePickerExceptions")
REGSTR_VAL_CUSTOM_PROPERTY_CACHE_DATE                       Equ         TEXT("CustomPropertyCacheDate")
REGSTR_VAL_CUSTOM_PROPERTY_HW_ID_KEY                        Equ         TEXT("CustomPropertyHwIdKey")
REGSTR_VAL_LAST_UPDATE_TIME                                 Equ         TEXT("LastUpdateTime")
REGSTR_VAL_CONTAINERID                                      Equ         TEXT("ContainerID")

REGSTR_VALUE_DEVICE_OBJECT_NAME                             Equ         TEXT("DeviceObjectName")
REGSTR_VALUE_DEVICE_SYMBOLIC_NAME                           Equ         TEXT("DeviceSymbolicName")
REGSTR_VAL_EJECT_PRIORITY                                   Equ         TEXT("EjectPriority")

REGSTR_KEY_CONTROL                                          Equ         TEXT("Control")
REGSTR_VAL_ACTIVESERVICE                                    Equ         TEXT("ActiveService")
REGSTR_VAL_LINKED                                           Equ         TEXT("Linked")
REGSTR_VAL_PHYSICALDEVICEOBJECT                             Equ         TEXT("PhysicalDeviceObject")
REGSTR_VAL_REMOVAL_POLICY                                   Equ         TEXT("RemovalPolicy")

REGSTR_VAL_CURRENT_VERSION                                  Equ         TEXT("CurrentVersion")
REGSTR_VAL_CURRENT_BUILD                                    Equ         TEXT("CurrentBuildNumber")
REGSTR_VAL_CURRENT_CSDVERSION                               Equ         TEXT("CSDVersion")
REGSTR_VAL_CURRENT_TYPE                                     Equ         TEXT("CurrentType")

REGSTR_VAL_BITSPERPIXEL                                     Equ         TEXT("BitsPerPixel")
REGSTR_VAL_RESOLUTION                                       Equ         TEXT("Resolution")
REGSTR_VAL_DPILOGICALX                                      Equ         TEXT("DPILogicalX")
REGSTR_VAL_DPILOGICALY                                      Equ         TEXT("DPILogicalY")
REGSTR_VAL_DPIPHYSICALX                                     Equ         TEXT("DPIPhysicalX")
REGSTR_VAL_DPIPHYSICALY                                     Equ         TEXT("DPIPhysicalY")
REGSTR_VAL_REFRESHRATE                                      Equ         TEXT("RefreshRate")
REGSTR_VAL_DISPLAYFLAGS                                     Equ         TEXT("DisplayFlags")

REGSTR_PATH_CONTROLPANEL                                    Equ         TEXT("Control Panel")

REGSTR_PATH_CONTROLSFOLDER                                  Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Controls Folder")

REGSTR_VAL_DOSCP                                            Equ         TEXT("OEMCP")
REGSTR_VAL_WINCP                                            Equ         TEXT("ACP")

REGSTR_PATH_DYNA_ENUM                                       Equ         TEXT("Config Manager\Enum")

REGSTR_VAL_HARDWARE_KEY                                     Equ         TEXT("HardWareKey")
REGSTR_VAL_ALLOCATION                                       Equ         TEXT("Allocation")
REGSTR_VAL_PROBLEM                                          Equ         TEXT("Problem")
REGSTR_VAL_STATUS                                           Equ         TEXT("Status")

REGSTR_VAL_DONTUSEMEM                                       Equ         TEXT("DontAllocLastMem")

REGSTR_VAL_SYSTEMROOT                                       Equ         TEXT("SystemRoot")
REGSTR_VAL_BOOTCOUNT                                        Equ         TEXT("BootCount")
REGSTR_VAL_REALNETSTART                                     Equ         TEXT("RealNetStart")
REGSTR_VAL_MEDIA                                            Equ         TEXT("MediaPath")
REGSTR_VAL_CONFIG                                           Equ         TEXT("ConfigPath")
REGSTR_VAL_DEVICEPATH                                       Equ         TEXT("DevicePath")
REGSTR_VAL_SRCPATH                                          Equ         TEXT("SourcePath")
REGSTR_VAL_DRIVERCACHEPATH                                  Equ         TEXT("DriverCachePath")

REGSTR_VAL_OLDWINDIR                                        Equ         TEXT("OldWinDir")
REGSTR_VAL_SETUPFLAGS                                       Equ         TEXT("SetupFlags")
REGSTR_VAL_REGOWNER                                         Equ         TEXT("RegisteredOwner")
REGSTR_VAL_REGORGANIZATION                                  Equ         TEXT("RegisteredOrganization")
REGSTR_VAL_LICENSINGINFO                                    Equ         TEXT("LicensingInfo")
REGSTR_VAL_OLDMSDOSVER                                      Equ         TEXT("OldMSDOSVer")
REGSTR_VAL_FIRSTINSTALLDATETIME                             Equ         TEXT("FirstInstallDateTime")

REGSTR_VAL_INSTALLTYPE                                      Equ         TEXT("InstallType")

IT_COMPACT                                                  Equ         0000H
IT_TYPICAL                                                  Equ         0001H
IT_PORTABLE                                                 Equ         0002H
IT_CUSTOM                                                   Equ         0003H

REGSTR_VAL_WRAPPER                                          Equ         TEXT("Wrapper")

REGSTR_KEY_RUNHISTORY                                       Equ         TEXT("RunHistory")
REGSTR_VAL_LASTALIVEINTERVAL                                Equ         TEXT("TimeStampInterval")
REGSTR_VAL_DIRTYSHUTDOWN                                    Equ         TEXT("DirtyShutdown")
REGSTR_VAL_DIRTYSHUTDOWNTIME                                Equ         TEXT("DirtyShutdownTime")
REGSTR_VAL_BT                                               Equ         TEXT("6005BT")
REGSTR_VAL_LASTCOMPUTERNAME                                 Equ         TEXT("LastComputerName")
REGSTR_VAL_LASTALIVEBT                                      Equ         TEXT("LastAliveBT")
REGSTR_VAL_LASTALIVESTAMP                                   Equ         TEXT("LastAliveStamp")
REGSTR_VAL_LASTALIVESTAMPFORCED                             Equ         TEXT("LastAliveStampForced")
REGSTR_VAL_LASTALIVESTAMPINTERVAL                           Equ         TEXT("LastAliveStampInterval")
REGSTR_VAL_LASTALIVESTAMPPOLICYINTERVAL                     Equ         TEXT("LastAliveStampPolicyInterval")
REGSTR_VAL_LASTALIVEUPTIME                                  Equ         TEXT("LastAliveUptime")
REGSTR_VAL_LASTALIVEPMPOLICY                                Equ         TEXT("LastAlivePMPolicy")

REGSTR_VAL_REASONCODE                                       Equ         TEXT("ReasonCode")
REGSTR_VAL_COMMENT                                          Equ         TEXT("Comment")

REGSTR_VAL_SHUTDOWNREASON                                   Equ         TEXT("ShutdownReason")
REGSTR_VAL_SHUTDOWNREASON_CODE                              Equ         TEXT("ShutdownReasonCode")
REGSTR_VAL_SHUTDOWNREASON_COMMENT                           Equ         TEXT("ShutdownReasonComment")
REGSTR_VAL_SHUTDOWNREASON_PROCESS                           Equ         TEXT("ShutdownReasonProcess")
REGSTR_VAL_SHUTDOWNREASON_USERNAME                          Equ         TEXT("ShutdownReasonUserName")
REGSTR_VAL_SHOWREASONUI                                     Equ         TEXT("ShutdownReasonUI")
REGSTR_VAL_SHUTDOWN_IGNORE_PREDEFINED                       Equ         TEXT("ShutdownIgnorePredefinedReasons")
REGSTR_VAL_SHUTDOWN_STATE_SNAPSHOT                          Equ         TEXT("ShutdownStateSnapshot")

REGSTR_KEY_SETUP                                            Equ         TEXT("\Setup")
REGSTR_VAL_BOOTDIR                                          Equ         TEXT("BootDir")
REGSTR_VAL_WINBOOTDIR                                       Equ         TEXT("WinbootDir")
REGSTR_VAL_WINDIR                                           Equ         TEXT("WinDir")

REGSTR_VAL_APPINSTPATH                                      Equ         TEXT("AppInstallPath")

REGSTR_PATH_EBD                                             Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Setup\EBD")

REGSTR_KEY_EBDFILESLOCAL                                    Equ         TEXT("EBDFilesLocale")
REGSTR_KEY_EBDFILESKEYBOARD                                 Equ         TEXT("EBDFilesKeyboard")
REGSTR_KEY_EBDAUTOEXECBATLOCAL                              Equ         TEXT("EBDAutoexecBatLocale")
REGSTR_KEY_EBDAUTOEXECBATKEYBOARD                           Equ         TEXT("EBDAutoexecBatKeyboard")
REGSTR_KEY_EBDCONFIGSYSLOCAL                                Equ         TEXT("EBDConfigSysLocale")
REGSTR_KEY_EBDCONFIGSYSKEYBOARD                             Equ         TEXT("EBDConfigSysKeyboard")

REGSTR_VAL_POLICY                                           Equ         TEXT("Policy")

REGSTR_VAL_BEHAVIOR_ON_FAILED_VERIFY                        Equ         TEXT("BehaviorOnFailedVerify")

DRIVERSIGN_NONE                                             Equ         00000000H
DRIVERSIGN_WARNING                                          Equ         00000001H
DRIVERSIGN_BLOCKING                                         Equ         00000002H

REGSTR_VAL_MSDOSMODE                                        Equ         TEXT("MSDOSMode")
REGSTR_VAL_MSDOSMODEDISCARD                                 Equ         TEXT("Discard")

REGSTR_VAL_DOSOPTGLOBALFLAGS                                Equ         TEXT("GlobalFlags")

DOSOPTGF_DEFCLEAN                                           Equ         00000001H

REGSTR_VAL_DOSOPTFLAGS                                      Equ         TEXT("Flags")
REGSTR_VAL_OPTORDER                                         Equ         TEXT("Order")
REGSTR_VAL_CONFIGSYS                                        Equ         TEXT("Config.Sys")
REGSTR_VAL_AUTOEXEC                                         Equ         TEXT("Autoexec.Bat")
REGSTR_VAL_STDDOSOPTION                                     Equ         TEXT("StdOption")
REGSTR_VAL_DOSOPTTIP                                        Equ         TEXT("TipText")

DOSOPTF_DEFAULT                                             Equ         00000001H
DOSOPTF_SUPPORTED                                           Equ         00000002H
DOSOPTF_ALWAYSUSE                                           Equ         00000004H
DOSOPTF_USESPMODE                                           Equ         00000008H
DOSOPTF_PROVIDESUMB                                         Equ         00000010H
DOSOPTF_NEEDSETUP                                           Equ         00000020H
DOSOPTF_INDOSSTART                                          Equ         00000040H
DOSOPTF_MULTIPLE                                            Equ         00000080H

SUF_FIRSTTIME                                               Equ         00000001H
SUF_EXPRESS                                                 Equ         00000002H
SUF_BATCHINF                                                Equ         00000004H
SUF_CLEAN                                                   Equ         00000008H
SUF_INSETUP                                                 Equ         00000010H
SUF_NETSETUP                                                Equ         00000020H
SUF_NETHDBOOT                                               Equ         00000040H
SUF_NETRPLBOOT                                              Equ         00000080H
SUF_SBSCOPYOK                                               Equ         00000100H

REGSTR_VAL_DOSPAGER                                         Equ         TEXT("DOSPager")
REGSTR_VAL_VXDGROUPS                                        Equ         TEXT("VXDGroups")
REGSTR_VAL_VPOWERDFLAGS                                     Equ         TEXT("Flags")

VPDF_DISABLEPWRMGMT                                         Equ         00000001H
VPDF_FORCEAPM10MODE                                         Equ         00000002H
VPDF_SKIPINTELSLCHECK                                       Equ         00000004H
VPDF_DISABLEPWRSTATUSPOLL                                   Equ         00000008H
VPDF_DISABLERINGRESUME                                      Equ         00000010H
VPDF_SHOWMULTIBATT                                          Equ         00000020H

BIF_SHOWSIMILARDRIVERS                                      Equ         00000001H
BIF_RAWDEVICENEEDSDRIVER                                    Equ         00000002H

REGSTR_VAL_WORKGROUP                                        Equ         TEXT("Workgroup")
REGSTR_VAL_DIRECTHOST                                       Equ         TEXT("DirectHost")
REGSTR_VAL_FILESHARING                                      Equ         TEXT("FileSharing")
REGSTR_VAL_PRINTSHARING                                     Equ         TEXT("PrintSharing")

REGSTR_VAL_FIRSTNETDRIVE                                    Equ         TEXT("FirstNetworkDrive")
REGSTR_VAL_MAXCONNECTIONS                                   Equ         TEXT("MaxConnections")
REGSTR_VAL_APISUPPORT                                       Equ         TEXT("APISupport")
REGSTR_VAL_MAXRETRY                                         Equ         TEXT("MaxRetry")
REGSTR_VAL_MINRETRY                                         Equ         TEXT("MinRetry")
REGSTR_VAL_SUPPORTLFN                                       Equ         TEXT("SupportLFN")
REGSTR_VAL_SUPPORTBURST                                     Equ         TEXT("SupportBurst")
REGSTR_VAL_SUPPORTTUNNELLING                                Equ         TEXT("SupportTunnelling")
REGSTR_VAL_FULLTRACE                                        Equ         TEXT("FullTrace")
REGSTR_VAL_READCACHING                                      Equ         TEXT("ReadCaching")
REGSTR_VAL_SHOWDOTS                                         Equ         TEXT("ShowDots")
REGSTR_VAL_GAPTIME                                          Equ         TEXT("GapTime")
REGSTR_VAL_SEARCHMODE                                       Equ         TEXT("SearchMode")
REGSTR_VAL_SHELLVERSION                                     Equ         TEXT("ShellVersion")
REGSTR_VAL_MAXLIP                                           Equ         TEXT("MaxLIP")
REGSTR_VAL_PRESERVECASE                                     Equ         TEXT("PreserveCase")
REGSTR_VAL_OPTIMIZESFN                                      Equ         TEXT("OptimizeSFN")

REGSTR_VAL_NCP_BROWSEMASTER                                 Equ         TEXT("BrowseMaster")
REGSTR_VAL_NCP_USEPEERBROWSING                              Equ         TEXT("Use_PeerBrowsing")
REGSTR_VAL_NCP_USESAP                                       Equ         TEXT("Use_Sap")

REGSTR_VAL_PCCARD_POWER                                     Equ         TEXT("EnablePowerManagement")

REGSTR_VAL_WIN31FILESYSTEM                                  Equ         TEXT("Win31FileSystem")
REGSTR_VAL_PRESERVELONGNAMES                                Equ         TEXT("PreserveLongNames")
REGSTR_VAL_DRIVEWRITEBEHIND                                 Equ         TEXT("DriveWriteBehind")
REGSTR_VAL_ASYNCFILECOMMIT                                  Equ         TEXT("AsyncFileCommit")
REGSTR_VAL_PATHCACHECOUNT                                   Equ         TEXT("PathCache")
REGSTR_VAL_NAMECACHECOUNT                                   Equ         TEXT("NameCache")
REGSTR_VAL_CONTIGFILEALLOC                                  Equ         TEXT("ContigFileAllocSize")
REGSTR_VAL_FREESPACERATIO                                   Equ         TEXT("FreeSpaceRatio")
REGSTR_VAL_VOLIDLETIMEOUT                                   Equ         TEXT("VolumeIdleTimeout")
REGSTR_VAL_BUFFIDLETIMEOUT                                  Equ         TEXT("BufferIdleTimeout")
REGSTR_VAL_BUFFAGETIMEOUT                                   Equ         TEXT("BufferAgeTimeout")
REGSTR_VAL_NAMENUMERICTAIL                                  Equ         TEXT("NameNumericTail")
REGSTR_VAL_READAHEADTHRESHOLD                               Equ         TEXT("ReadAheadThreshold")
REGSTR_VAL_DOUBLEBUFFER                                     Equ         TEXT("DoubleBuffer")
REGSTR_VAL_SOFTCOMPATMODE                                   Equ         TEXT("SoftCompatMode")
REGSTR_VAL_DRIVESPINDOWN                                    Equ         TEXT("DriveSpinDown")
REGSTR_VAL_FORCEPMIO                                        Equ         TEXT("ForcePMIO")
REGSTR_VAL_FORCERMIO                                        Equ         TEXT("ForceRMIO")
REGSTR_VAL_LASTBOOTPMDRVS                                   Equ         TEXT("LastBootPMDrvs")
REGSTR_VAL_ACSPINDOWNPREVIOUS                               Equ         TEXT("ACSpinDownPrevious")
REGSTR_VAL_BATSPINDOWNPREVIOUS                              Equ         TEXT("BatSpinDownPrevious")
REGSTR_VAL_VIRTUALHDIRQ                                     Equ         TEXT("VirtualHDIRQ")
REGSTR_VAL_SRVNAMECACHECOUNT                                Equ         TEXT("ServerNameCacheMax")
REGSTR_VAL_SRVNAMECACHE                                     Equ         TEXT("ServerNameCache")
REGSTR_VAL_SRVNAMECACHENETPROV                              Equ         TEXT("ServerNameCacheNumNets")
REGSTR_VAL_AUTOMOUNT                                        Equ         TEXT("AutoMountDrives")
REGSTR_VAL_COMPRESSIONMETHOD                                Equ         TEXT("CompressionAlgorithm")
REGSTR_VAL_COMPRESSIONTHRESHOLD                             Equ         TEXT("CompressionThreshold")
REGSTR_VAL_ACDRIVESPINDOWN                                  Equ         TEXT("ACDriveSpinDown")
REGSTR_VAL_BATDRIVESPINDOWN                                 Equ         TEXT("BatDriveSpinDown")

REGSTR_VAL_CDCACHESIZE                                      Equ         TEXT("CacheSize")
REGSTR_VAL_CDPREFETCH                                       Equ         TEXT("Prefetch")
REGSTR_VAL_CDPREFETCHTAIL                                   Equ         TEXT("PrefetchTail")
REGSTR_VAL_CDRAWCACHE                                       Equ         TEXT("RawCache")
REGSTR_VAL_CDEXTERRORS                                      Equ         TEXT("ExtendedErrors")
REGSTR_VAL_CDSVDSENSE                                       Equ         TEXT("SVDSense")
REGSTR_VAL_CDSHOWVERSIONS                                   Equ         TEXT("ShowVersions")
REGSTR_VAL_CDCOMPATNAMES                                    Equ         TEXT("MSCDEXCompatNames")
REGSTR_VAL_CDNOREADAHEAD                                    Equ         TEXT("NoReadAhead")

REGSTR_VAL_SCSI                                             Equ         TEXT("SCSI\")
REGSTR_VAL_ESDI                                             Equ         TEXT("ESDI\")
REGSTR_VAL_FLOP                                             Equ         TEXT("FLOP\")

REGSTR_VAL_DISK                                             Equ         TEXT("GenDisk")
REGSTR_VAL_CDROM                                            Equ         TEXT("GenCD")
REGSTR_VAL_TAPE                                             Equ         TEXT("TAPE")
REGSTR_VAL_SCANNER                                          Equ         TEXT("SCANNER")
REGSTR_VAL_FLOPPY                                           Equ         TEXT("FLOPPY")

REGSTR_VAL_SCSITID                                          Equ         TEXT("SCSITargetID")
REGSTR_VAL_SCSILUN                                          Equ         TEXT("SCSILUN")
REGSTR_VAL_REVLEVEL                                         Equ         TEXT("RevisionLevel")
REGSTR_VAL_PRODUCTID                                        Equ         TEXT("ProductId")
REGSTR_VAL_PRODUCTTYPE                                      Equ         TEXT("ProductType")
REGSTR_VAL_DEVTYPE                                          Equ         TEXT("DeviceType")
REGSTR_VAL_REMOVABLE                                        Equ         TEXT("Removable")
REGSTR_VAL_CURDRVLET                                        Equ         TEXT("CurrentDriveLetterAssignment")
REGSTR_VAL_USRDRVLET                                        Equ         TEXT("UserDriveLetterAssignment")
REGSTR_VAL_SYNCDATAXFER                                     Equ         TEXT("SyncDataXfer")
REGSTR_VAL_AUTOINSNOTE                                      Equ         TEXT("AutoInsertNotification")
REGSTR_VAL_DISCONNECT                                       Equ         TEXT("Disconnect")
REGSTR_VAL_INT13                                            Equ         TEXT("Int13")
REGSTR_VAL_PMODE_INT13                                      Equ         TEXT("PModeInt13")
REGSTR_VAL_USERSETTINGS                                     Equ         TEXT("AdapterSettings")
REGSTR_VAL_NOIDE                                            Equ         TEXT("NoIDE")

REGSTR_VAL_DISKCLASSNAME                                    Equ         TEXT("DiskDrive")
REGSTR_VAL_CDROMCLASSNAME                                   Equ         TEXT("CDROM")

REGSTR_VAL_FORCELOAD                                        Equ         TEXT("ForceLoadPD")

REGSTR_VAL_FORCEFIFO                                        Equ         TEXT("ForceFIFO")
REGSTR_VAL_FORCECL                                          Equ         TEXT("ForceChangeLine")

REGSTR_VAL_NOUSECLASS                                       Equ         TEXT("NoUseClass")
REGSTR_VAL_NOINSTALLCLASS                                   Equ         TEXT("NoInstallClass")
REGSTR_VAL_NODISPLAYCLASS                                   Equ         TEXT("NoDisplayClass")
REGSTR_VAL_SILENTINSTALL                                    Equ         TEXT("SilentInstall")

REGSTR_KEY_PCMCIA_CLASS                                     Equ         TEXT("PCMCIA")
REGSTR_KEY_SCSI_CLASS                                       Equ         TEXT("SCSIAdapter")
REGSTR_KEY_PORTS_CLASS                                      Equ         TEXT("ports")
REGSTR_KEY_MEDIA_CLASS                                      Equ         TEXT("MEDIA")
REGSTR_KEY_DISPLAY_CLASS                                    Equ         TEXT("Display")
REGSTR_KEY_KEYBOARD_CLASS                                   Equ         TEXT("Keyboard")
REGSTR_KEY_MOUSE_CLASS                                      Equ         TEXT("Mouse")
REGSTR_KEY_MONITOR_CLASS                                    Equ         TEXT("Monitor")
REGSTR_KEY_MODEM_CLASS                                      Equ         TEXT("Modem")

REGSTR_VAL_PCMCIA_OPT                                       Equ         TEXT("Options")
PCMCIA_OPT_HAVE_SOCKET                                      Equ         00000001H
PCMCIA_OPT_ENABLED                                          Equ         00000002H
PCMCIA_OPT_AUTOMEM                                          Equ         00000004H
PCMCIA_OPT_NO_SOUND                                         Equ         00000008H
PCMCIA_OPT_NO_AUDIO                                         Equ         00000010H
PCMCIA_OPT_NO_APMREMOVE                                     Equ         00000020H

REGSTR_VAL_PCMCIA_MEM                                       Equ         TEXT("Memory")
PCMCIA_DEF_MEMBEGIN                                         Equ         000C0000H
PCMCIA_DEF_MEMEND                                           Equ         00FFFFFFH
PCMCIA_DEF_MEMLEN                                           Equ         00001000H

REGSTR_VAL_PCMCIA_ALLOC                                     Equ         TEXT("AllocMemWin")
REGSTR_VAL_PCMCIA_ATAD                                      Equ         TEXT("ATADelay")

REGSTR_VAL_PCMCIA_SIZ                                       Equ         TEXT("MinRegionSize")
PCMCIA_DEF_MIN_REGION                                       Equ         00010000H

REGSTR_VAL_P1284MDL                                         Equ         TEXT("Model")
REGSTR_VAL_P1284MFG                                         Equ         TEXT("Manufacturer")

REGSTR_VAL_ISAPNP                                           Equ         TEXT("ISAPNP")
REGSTR_VAL_ISAPNP_RDP_OVERRIDE                              Equ         TEXT("RDPOverRide")

REGSTR_VAL_PCI                                              Equ         TEXT("PCI")
REGSTR_PCI_OPTIONS                                          Equ         TEXT("Options")
REGSTR_PCI_DUAL_IDE                                         Equ         TEXT("PCIDualIDE")
PCI_OPTIONS_USE_BIOS                                        Equ         00000001H
PCI_OPTIONS_USE_IRQ_STEERING                                Equ         00000002H

AGP_FLAG_NO_1X_RATE                                         Equ         00000001H
AGP_FLAG_NO_2X_RATE                                         Equ         00000002H
AGP_FLAG_NO_4X_RATE                                         Equ         00000004H
AGP_FLAG_NO_8X_RATE                                         Equ         00000008H
AGP_FLAG_REVERSE_INITIALIZATION                             Equ         00000080H

AGP_FLAG_NO_SBA_ENABLE                                      Equ         00000100H
AGP_FLAG_NO_FW_ENABLE                                       Equ         00000200H

AGP_FLAG_SPECIAL_TARGET                                     Equ         000FFFFFH
AGP_FLAG_SPECIAL_RESERVE                                    Equ         000F8000H

REGSTR_KEY_CRASHES                                          Equ         TEXT("Crashes")
REGSTR_KEY_DANGERS                                          Equ         TEXT("Dangers")
REGSTR_KEY_DETMODVARS                                       Equ         TEXT("DetModVars")
REGSTR_KEY_NDISINFO                                         Equ         TEXT("NDISInfo")
REGSTR_VAL_PROTINIPATH                                      Equ         TEXT("ProtIniPath")
REGSTR_VAL_RESOURCES                                        Equ         TEXT("Resources")
REGSTR_VAL_CRASHFUNCS                                       Equ         TEXT("CrashFuncs")
REGSTR_VAL_CLASS                                            Equ         TEXT("Class")
REGSTR_VAL_CLASSDESC                                        Equ         TEXT("ClassDesc")
REGSTR_VAL_DEVDESC                                          Equ         TEXT("DeviceDesc")
REGSTR_VAL_BOOTCONFIG                                       Equ         TEXT("BootConfig")
REGSTR_VAL_DETFUNC                                          Equ         TEXT("DetFunc")
REGSTR_VAL_DETFLAGS                                         Equ         TEXT("DetFlags")
REGSTR_VAL_COMPATIBLEIDS                                    Equ         TEXT("CompatibleIDs")
REGSTR_VAL_DETCONFIG                                        Equ         TEXT("DetConfig")
REGSTR_VAL_VERIFYKEY                                        Equ         TEXT("VerifyKey")
REGSTR_VAL_COMINFO                                          Equ         TEXT("ComInfo")
REGSTR_VAL_INFNAME                                          Equ         TEXT("InfName")
REGSTR_VAL_CARDSPECIFIC                                     Equ         TEXT("CardSpecific")
REGSTR_VAL_NETOSTYPE                                        Equ         TEXT("NetOSType")
REGSTR_DATA_NETOS_NDIS                                      Equ         TEXT("NDIS")
REGSTR_DATA_NETOS_ODI                                       Equ         TEXT("ODI")
REGSTR_DATA_NETOS_IPX                                       Equ         TEXT("IPX")
REGSTR_VAL_MFG                                              Equ         TEXT("Mfg")
REGSTR_VAL_SCAN_ONLY_FIRST                                  Equ         TEXT("ScanOnlyFirstDrive")
REGSTR_VAL_SHARE_IRQ                                        Equ         TEXT("ForceIRQSharing")
REGSTR_VAL_NONSTANDARD_ATAPI                                Equ         TEXT("NonStandardATAPI")
REGSTR_VAL_IDE_FORCE_SERIALIZE                              Equ         TEXT("ForceSerialization")
REGSTR_VAL_MAX_HCID_LEN                                     Equ         1024
REGSTR_VAL_HWREV                                            Equ         TEXT("HWRevision")
REGSTR_VAL_ENABLEINTS                                       Equ         TEXT("EnableInts")

REGDF_NOTDETIO                                              Equ         00000001H
REGDF_NOTDETMEM                                             Equ         00000002H
REGDF_NOTDETIRQ                                             Equ         00000004H
REGDF_NOTDETDMA                                             Equ         00000008H
REGDF_NOTDETALL                                             Equ         (REGDF_NOTDETIO Or REGDF_NOTDETMEM Or REGDF_NOTDETIRQ Or REGDF_NOTDETDMA)
REGDF_NEEDFULLCONFIG                                        Equ         00000010H
REGDF_GENFORCEDCONFIG                                       Equ         00000020H
REGDF_NODETCONFIG                                           Equ         00008000H
REGDF_CONFLICTIO                                            Equ         00010000H
REGDF_CONFLICTMEM                                           Equ         00020000H
REGDF_CONFLICTIRQ                                           Equ         00040000H
REGDF_CONFLICTDMA                                           Equ         00080000H
REGDF_CONFLICTALL                                           Equ         (REGDF_CONFLICTIO Or REGDF_CONFLICTMEM Or REGDF_CONFLICTIRQ Or REGDF_CONFLICTDMA)
REGDF_MAPIRQ2TO9                                            Equ         00100000H
REGDF_NOTVERIFIED                                           Equ         80000000H

REGSTR_VAL_APMBIOSVER                                       Equ         TEXT("APMBiosVer")
REGSTR_VAL_APMFLAGS                                         Equ         TEXT("APMFlags")
REGSTR_VAL_SLSUPPORT                                        Equ         TEXT("SLSupport")
REGSTR_VAL_MACHINETYPE                                      Equ         TEXT("MachineType")
REGSTR_VAL_SETUPMACHINETYPE                                 Equ         TEXT("SetupMachineType")
REGSTR_MACHTYPE_UNKNOWN                                     Equ         TEXT("Unknown")
REGSTR_MACHTYPE_IBMPC                                       Equ         TEXT("IBM PC")
REGSTR_MACHTYPE_IBMPCJR                                     Equ         TEXT("IBM PCjr")
REGSTR_MACHTYPE_IBMPCCONV                                   Equ         TEXT("IBM PC Convertible")
REGSTR_MACHTYPE_IBMPCXT                                     Equ         TEXT("IBM PC/XT")
REGSTR_MACHTYPE_IBMPCXT_286                                 Equ         TEXT("IBM PC/XT 286")
REGSTR_MACHTYPE_IBMPCAT                                     Equ         TEXT("IBM PC/AT")
REGSTR_MACHTYPE_IBMPS2_25                                   Equ         TEXT("IBM PS/2-25")
REGSTR_MACHTYPE_IBMPS2_30_286                               Equ         TEXT("IBM PS/2-30 286")
REGSTR_MACHTYPE_IBMPS2_30                                   Equ         TEXT("IBM PS/2-30")
REGSTR_MACHTYPE_IBMPS2_50                                   Equ         TEXT("IBM PS/2-50")
REGSTR_MACHTYPE_IBMPS2_50Z                                  Equ         TEXT("IBM PS/2-50Z")
REGSTR_MACHTYPE_IBMPS2_55SX                                 Equ         TEXT("IBM PS/2-55SX")
REGSTR_MACHTYPE_IBMPS2_60                                   Equ         TEXT("IBM PS/2-60")
REGSTR_MACHTYPE_IBMPS2_65SX                                 Equ         TEXT("IBM PS/2-65SX")
REGSTR_MACHTYPE_IBMPS2_70                                   Equ         TEXT("IBM PS/2-70")
REGSTR_MACHTYPE_IBMPS2_P70                                  Equ         TEXT("IBM PS/2-P70")
REGSTR_MACHTYPE_IBMPS2_70_80                                Equ         TEXT("IBM PS/2-70/80")
REGSTR_MACHTYPE_IBMPS2_80                                   Equ         TEXT("IBM PS/2-80")
REGSTR_MACHTYPE_IBMPS2_90                                   Equ         TEXT("IBM PS/2-90")
REGSTR_MACHTYPE_IBMPS1                                      Equ         TEXT("IBM PS/1")
REGSTR_MACHTYPE_PHOENIX_PCAT                                Equ         TEXT("Phoenix PC/AT Compatible")
REGSTR_MACHTYPE_HP_VECTRA                                   Equ         TEXT("HP Vectra")
REGSTR_MACHTYPE_ATT_PC                                      Equ         TEXT("AT&T PC")
REGSTR_MACHTYPE_ZENITH_PC                                   Equ         TEXT("Zenith PC")

REGSTR_VAL_APMMENUSUSPEND                                   Equ         TEXT("APMMenuSuspend")
APMMENUSUSPEND_DISABLED                                     Equ         0
APMMENUSUSPEND_ENABLED                                      Equ         1
APMMENUSUSPEND_UNDOCKED                                     Equ         2
APMMENUSUSPEND_NOCHANGE                                     Equ         80H

REGSTR_VAL_APMACTIMEOUT                                     Equ         TEXT("APMACTimeout")
REGSTR_VAL_APMBATTIMEOUT                                    Equ         TEXT("APMBatTimeout")
APMTIMEOUT_DISABLED                                         Equ         0

REGSTR_VAL_APMSHUTDOWNPOWER                                 Equ         TEXT("APMShutDownPower")

REGSTR_VAL_BUSTYPE                                          Equ         TEXT("BusType")
REGSTR_VAL_CPU                                              Equ         TEXT("CPU")
REGSTR_VAL_NDP                                              Equ         TEXT("NDP")
REGSTR_VAL_PNPBIOSVER                                       Equ         TEXT("PnPBIOSVer")
REGSTR_VAL_PNPSTRUCOFFSET                                   Equ         TEXT("PnPStrucOffset")
REGSTR_VAL_PCIBIOSVER                                       Equ         TEXT("PCIBIOSVer")
REGSTR_VAL_HWMECHANISM                                      Equ         TEXT("HWMechanism")
REGSTR_VAL_LASTPCIBUSNUM                                    Equ         TEXT("LastPCIBusNum")
REGSTR_VAL_CONVMEM                                          Equ         TEXT("ConvMem")
REGSTR_VAL_EXTMEM                                           Equ         TEXT("ExtMem")
REGSTR_VAL_COMPUTERNAME                                     Equ         TEXT("ComputerName")
REGSTR_VAL_BIOSNAME                                         Equ         TEXT("BIOSName")
REGSTR_VAL_BIOSVERSION                                      Equ         TEXT("BIOSVersion")
REGSTR_VAL_BIOSDATE                                         Equ         TEXT("BIOSDate")
REGSTR_VAL_MODEL                                            Equ         TEXT("Model")
REGSTR_VAL_SUBMODEL                                         Equ         TEXT("Submodel")
REGSTR_VAL_REVISION                                         Equ         TEXT("Revision")

REGSTR_VAL_FIFODEPTH                                        Equ         TEXT("FIFODepth")
REGSTR_VAL_RDINTTHRESHOLD                                   Equ         TEXT("RDIntThreshold")
REGSTR_VAL_WRINTTHRESHOLD                                   Equ         TEXT("WRIntThreshold")

REGSTR_VAL_PRIORITY                                         Equ         TEXT("Priority")
REGSTR_VAL_DRIVER                                           Equ         TEXT("Driver")
REGSTR_VAL_FUNCDESC                                         Equ         TEXT("FunctionDesc")
REGSTR_VAL_FORCEDCONFIG                                     Equ         TEXT("ForcedConfig")
REGSTR_VAL_CONFIGFLAGS                                      Equ         TEXT("ConfigFlags")
REGSTR_VAL_CSCONFIGFLAGS                                    Equ         TEXT("CSConfigFlags")

CONFIGFLAG_DISABLED                                         Equ         00000001H
CONFIGFLAG_REMOVED                                          Equ         00000002H
CONFIGFLAG_MANUAL_INSTALL                                   Equ         00000004H
CONFIGFLAG_IGNORE_BOOT_LC                                   Equ         00000008H
CONFIGFLAG_NET_BOOT                                         Equ         00000010H
CONFIGFLAG_REINSTALL                                        Equ         00000020H
CONFIGFLAG_FAILEDINSTALL                                    Equ         00000040H
CONFIGFLAG_CANTSTOPACHILD                                   Equ         00000080H
CONFIGFLAG_OKREMOVEROM                                      Equ         00000100H
CONFIGFLAG_NOREMOVEEXIT                                     Equ         00000200H
CONFIGFLAG_FINISH_INSTALL                                   Equ         00000400H
CONFIGFLAG_NEEDS_FORCED_CONFIG                              Equ         00000800H
CONFIGFLAG_NETBOOT_CARD                                     Equ         00001000H
CONFIGFLAG_PARTIAL_LOG_CONF                                 Equ         00002000H
CONFIGFLAG_SUPPRESS_SURPRISE                                Equ         00004000H
CONFIGFLAG_VERIFY_HARDWARE                                  Equ         00008000H
CONFIGFLAG_FINISHINSTALL_UI                                 Equ         00010000H
CONFIGFLAG_FINISHINSTALL_ACTION                             Equ         00020000H

CSCONFIGFLAG_BITS                                           Equ         00000007H
CSCONFIGFLAG_DISABLED                                       Equ         00000001H
CSCONFIGFLAG_DO_NOT_CREATE                                  Equ         00000002H
CSCONFIGFLAG_DO_NOT_START                                   Equ         00000004H

DMSTATEFLAG_APPLYTOALL                                      Equ         00000001H

REGSTR_VAL_ROOT_DEVNODE                                     Equ         TEXT("HTREE\ROOT\0")
REGSTR_VAL_RESERVED_DEVNODE                                 Equ         TEXT("HTREE\RESERVED\0")
IFNDEF NEC_98
    REGSTR_PATH_READDATAPORT                                Equ         TEXT("ISAPnP\ReadDataPort\0")
ELSE
    REGSTR_PATH_READDATAPORT                                Equ         TEXT("C98PnP\ReadDataPort\0")
ENDIF

REGSTR_PATH_MULTI_FUNCTION                                  Equ         TEXT("MF")
REGSTR_VAL_RESOURCE_MAP                                     Equ         TEXT("ResourceMap")
REGSTR_PATH_CHILD_PREFIX                                    Equ         TEXT("Child")
NUM_RESOURCE_MAP                                            Equ         256
REGSTR_VAL_MF_FLAGS                                         Equ         TEXT("MFFlags")
MF_FLAGS_EVEN_IF_NO_RESOURCE                                Equ         00000001H
MF_FLAGS_NO_CREATE_IF_NO_RESOURCE                           Equ         00000002H
MF_FLAGS_FILL_IN_UNKNOWN_RESOURCE                           Equ         00000004H
MF_FLAGS_CREATE_BUT_NO_SHOW_DISABLED                        Equ         00000008H

IFNDEF NEC_98
    REGSTR_VAL_EISA_RANGES                                  Equ         TEXT("EISARanges")
    REGSTR_VAL_EISA_FUNCTIONS                               Equ         TEXT("EISAFunctions")
    REGSTR_VAL_EISA_FUNCTIONS_MASK                          Equ         TEXT("EISAFunctionsMask")
    REGSTR_VAL_EISA_FLAGS                                   Equ         TEXT("EISAFlags")
    REGSTR_VAL_EISA_SIMULATE_INT15                          Equ         TEXT("EISASimulateInt15")
ELSE
    REGSTR_VAL_EISA_RANGES                                  Equ         TEXT("NESARanges")
    REGSTR_VAL_EISA_FUNCTIONS                               Equ         TEXT("NESAFunctions")
    REGSTR_VAL_EISA_FUNCTIONS_MASK                          Equ         TEXT("NESAFunctionsMask")
    REGSTR_VAL_EISA_FLAGS                                   Equ         TEXT("NESAFlags")
    REGSTR_VAL_EISA_SIMULATE_INT15                          Equ         TEXT("NESASimulateInt15")
ENDIF
EISAFLAG_NO_IO_MERGE                                        Equ         00000001H
EISAFLAG_SLOT_IO_FIRST                                      Equ         00000002H
EISA_NO_MAX_FUNCTION                                        Equ         0FFH
NUM_EISA_RANGES                                             Equ         04H


REGSTR_VAL_DRVDESC                                          Equ         TEXT("DriverDesc")
REGSTR_VAL_DEVLOADER                                        Equ         TEXT("DevLoader")
REGSTR_VAL_STATICVXD                                        Equ         TEXT("StaticVxD")
REGSTR_VAL_PROPERTIES                                       Equ         TEXT("Properties")
REGSTR_VAL_MANUFACTURER                                     Equ         TEXT("Manufacturer")
REGSTR_VAL_EXISTS                                           Equ         TEXT("Exists")
REGSTR_VAL_CMENUMFLAGS                                      Equ         TEXT("CMEnumFlags")
REGSTR_VAL_CMDRIVFLAGS                                      Equ         TEXT("CMDrivFlags")
REGSTR_VAL_ENUMERATOR                                       Equ         TEXT("Enumerator")
REGSTR_VAL_DEVICEDRIVER                                     Equ         TEXT("DeviceDriver")
REGSTR_VAL_PORTNAME                                         Equ         TEXT("PortName")
REGSTR_VAL_INFPATH                                          Equ         TEXT("InfPath")
REGSTR_VAL_INFSECTION                                       Equ         TEXT("InfSection")
REGSTR_VAL_INFSECTIONEXT                                    Equ         TEXT("InfSectionExt")
REGSTR_VAL_POLLING                                          Equ         TEXT("Polling")
REGSTR_VAL_DONTLOADIFCONFLICT                               Equ         TEXT("DontLoadIfConflict")
REGSTR_VAL_PORTSUBCLASS                                     Equ         TEXT("PortSubClass")
REGSTR_VAL_NETCLEAN                                         Equ         TEXT("NetClean")
REGSTR_VAL_IDE_NO_SERIALIZE                                 Equ         TEXT("IDENoSerialize")
REGSTR_VAL_NOCMOSORFDPT                                     Equ         TEXT("NoCMOSorFDPT")
REGSTR_VAL_COMVERIFYBASE                                    Equ         TEXT("COMVerifyBase")
REGSTR_VAL_MATCHINGDEVID                                    Equ         TEXT("MatchingDeviceId")
REGSTR_VAL_DRIVERDATE                                       Equ         TEXT("DriverDate")
REGSTR_VAL_DRIVERDATEDATA                                   Equ         TEXT("DriverDateData")
REGSTR_VAL_DRIVERVERSION                                    Equ         TEXT("DriverVersion")
REGSTR_VAL_LOCATION_INFORMATION_OVERRIDE                    Equ         TEXT("LocationInformationOverride")

REGSTR_KEY_OVERRIDE                                         Equ         TEXT("Override")

REGSTR_VAL_CONFIGMG                                         Equ         TEXT("CONFIGMG")
REGSTR_VAL_SYSDM                                            Equ         TEXT("SysDM")
REGSTR_VAL_SYSDMFUNC                                        Equ         TEXT("SysDMFunc")
REGSTR_VAL_PRIVATE                                          Equ         TEXT("Private")
REGSTR_VAL_PRIVATEFUNC                                      Equ         TEXT("PrivateFunc")
REGSTR_VAL_DETECT                                           Equ         TEXT("Detect")
REGSTR_VAL_DETECTFUNC                                       Equ         TEXT("DetectFunc")
REGSTR_VAL_ASKFORCONFIG                                     Equ         TEXT("AskForConfig")
REGSTR_VAL_ASKFORCONFIGFUNC                                 Equ         TEXT("AskForConfigFunc")
REGSTR_VAL_WAITFORUNDOCK                                    Equ         TEXT("WaitForUndock")
REGSTR_VAL_WAITFORUNDOCKFUNC                                Equ         TEXT("WaitForUndockFunc")
REGSTR_VAL_REMOVEROMOKAY                                    Equ         TEXT("RemoveRomOkay")
REGSTR_VAL_REMOVEROMOKAYFUNC                                Equ         TEXT("RemoveRomOkayFunc")

REGSTR_VAL_CURCONFIG                                        Equ         TEXT("CurrentConfig")
REGSTR_VAL_FRIENDLYNAME                                     Equ         TEXT("FriendlyName")
REGSTR_VAL_CURRENTCONFIG                                    Equ         TEXT("CurrentConfig")
REGSTR_VAL_MAP                                              Equ         TEXT("Map")
REGSTR_VAL_ID                                               Equ         TEXT("CurrentID")
REGSTR_VAL_DOCKED                                           Equ         TEXT("CurrentDockedState")
REGSTR_VAL_CHECKSUM                                         Equ         TEXT("CurrentChecksum")
REGSTR_VAL_HWDETECT                                         Equ         TEXT("HardwareDetect")
REGSTR_VAL_INHIBITRESULTS                                   Equ         TEXT("InhibitResults")

REGSTR_VAL_PROFILEFLAGS                                     Equ         TEXT("ProfileFlags")

REGSTR_KEY_PCMCIA                                           Equ         TEXT("PCMCIA\")
REGSTR_KEY_PCUNKNOWN                                        Equ         TEXT("UNKNOWN_MANUFACTURER")
REGSTR_VAL_PCSSDRIVER                                       Equ         TEXT("Driver")
REGSTR_KEY_PCMTD                                            Equ         TEXT("MTD-")
REGSTR_VAL_PCMTDRIVER                                       Equ         TEXT("MTD")

REGSTR_VAL_HARDWAREID                                       Equ         TEXT("HardwareID")

REGSTR_VAL_INSTALLER                                        Equ         TEXT("Installer")
REGSTR_VAL_INSTALLER_32                                     Equ         TEXT("Installer32")
REGSTR_VAL_INSICON                                          Equ         TEXT("Icon")
REGSTR_VAL_ENUMPROPPAGES                                    Equ         TEXT("EnumPropPages")
REGSTR_VAL_ENUMPROPPAGES_32                                 Equ         TEXT("EnumPropPages32")
REGSTR_VAL_BASICPROPERTIES                                  Equ         TEXT("BasicProperties")
REGSTR_VAL_BASICPROPERTIES_32                               Equ         TEXT("BasicProperties32")
REGSTR_VAL_COINSTALLERS_32                                  Equ         TEXT("CoInstallers32")
REGSTR_VAL_PRIVATEPROBLEM                                   Equ         TEXT("PrivateProblem")

REGSTR_KEY_CURRENT                                          Equ         TEXT("Current")
REGSTR_KEY_DEFAULT                                          Equ         TEXT("Default")
REGSTR_KEY_MODES                                            Equ         TEXT("Modes")

REGSTR_VAL_MODE                                             Equ         TEXT("Mode")
REGSTR_VAL_BPP                                              Equ         TEXT("BPP")
REGSTR_VAL_HRES                                             Equ         TEXT("HRes")
REGSTR_VAL_VRES                                             Equ         TEXT("VRes")
REGSTR_VAL_FONTSIZE                                         Equ         TEXT("FontSize")
REGSTR_VAL_DRV                                              Equ         TEXT("drv")
REGSTR_VAL_GRB                                              Equ         TEXT("grb")
REGSTR_VAL_VDD                                              Equ         TEXT("vdd")
REGSTR_VAL_VER                                              Equ         TEXT("Ver")
REGSTR_VAL_MAXRES                                           Equ         TEXT("MaxResolution")
REGSTR_VAL_DPMS                                             Equ         TEXT("DPMS")
REGSTR_VAL_RESUMERESET                                      Equ         TEXT("ResumeReset")

REGSTR_VAL_DESCRIPTION                                      Equ         TEXT("Description")

REGSTR_KEY_SYSTEM                                           Equ         TEXT("System")
REGSTR_KEY_USER                                             Equ         TEXT("User")
REGSTR_VAL_DPI                                              Equ         TEXT("dpi")

REGSTR_VAL_PCICOPTIONS                                      Equ         TEXT("PCICOptions")

IFNDEF NEC_98
    PCIC_DEFAULT_IRQMASK                                    Equ         4EB8H
ELSE
    PCIC_DEFAULT_IRQMASK                                    Equ         1468H
ENDIF
PCIC_DEFAULT_NUMSOCKETS                                     Equ         0
REGSTR_VAL_PCICIRQMAP                                       Equ         TEXT("PCICIRQMap")

REGSTR_PATH_APPEARANCE                                      Equ         TEXT("Control Panel\Appearance")
REGSTR_PATH_LOOKSCHEMES                                     Equ         TEXT("Control Panel\Appearance\Schemes")
REGSTR_VAL_CUSTOMCOLORS                                     Equ         TEXT("CustomColors")

REGSTR_PATH_SCREENSAVE                                      Equ         TEXT("Control Panel\Desktop")
REGSTR_VALUE_USESCRPASSWORD                                 Equ         TEXT("ScreenSaveUsePassword")
REGSTR_VALUE_SCRPASSWORD                                    Equ         TEXT("ScreenSave_Data")

REGSTR_VALUE_LOWPOWERTIMEOUT                                Equ         TEXT("ScreenSaveLowPowerTimeout")
REGSTR_VALUE_POWEROFFTIMEOUT                                Equ         TEXT("ScreenSavePowerOffTimeout")
REGSTR_VALUE_LOWPOWERACTIVE                                 Equ         TEXT("ScreenSaveLowPowerActive")
REGSTR_VALUE_POWEROFFACTIVE                                 Equ         TEXT("ScreenSavePowerOffActive")

REGSTR_PATH_WINDOWSAPPLETS                                  Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Applets")

REGSTR_PATH_SYSTRAY                                         Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Applets\SysTray")
REGSTR_VAL_SYSTRAYSVCS                                      Equ         TEXT("Services")
REGSTR_VAL_SYSTRAYBATFLAGS                                  Equ         TEXT("PowerFlags")
REGSTR_VAL_SYSTRAYPCCARDFLAGS                               Equ         TEXT("PCMCIAFlags")

REGSTR_PATH_NETWORK_USERSETTINGS                            Equ         TEXT("Network")

REGSTR_KEY_NETWORK_PERSISTENT                               Equ         TEXT("\Persistent")
REGSTR_KEY_NETWORK_RECENT                                   Equ         TEXT("\Recent")
REGSTR_VAL_REMOTE_PATH                                      Equ         TEXT("RemotePath")
REGSTR_VAL_USER_NAME                                        Equ         TEXT("UserName")
REGSTR_VAL_PROVIDER_NAME                                    Equ         TEXT("ProviderName")
REGSTR_VAL_CONNECTION_TYPE                                  Equ         TEXT("ConnectionType")
REGSTR_VAL_UPGRADE                                          Equ         TEXT("Upgrade")

REGSTR_KEY_LOGON                                            Equ         TEXT("\Logon")
REGSTR_VAL_MUSTBEVALIDATED                                  Equ         TEXT("MustBeValidated")
REGSTR_VAL_RUNLOGINSCRIPT                                   Equ         TEXT("ProcessLoginScript")

REGSTR_KEY_NETWORKPROVIDER                                  Equ         TEXT("\NetworkProvider")
REGSTR_PATH_NW32NETPROVIDER                                 Equ         TEXT("System\CurrentControlSet\Services\NWNP32\NetworkProvider")
REGSTR_PATH_MS32NETPROVIDER                                 Equ         TEXT("System\CurrentControlSet\Services\MSNP32\NetworkProvider")
REGSTR_VAL_AUTHENT_AGENT                                    Equ         TEXT("AuthenticatingAgent")

REGSTR_VAL_PREFREDIR                                        Equ         TEXT("PreferredRedir")
REGSTR_VAL_AUTOSTART                                        Equ         TEXT("AutoStart")
REGSTR_VAL_AUTOLOGON                                        Equ         TEXT("AutoLogon")
REGSTR_VAL_NETCARD                                          Equ         TEXT("Netcard")
REGSTR_VAL_TRANSPORT                                        Equ         TEXT("Transport")
REGSTR_VAL_DYNAMIC                                          Equ         TEXT("Dynamic")
REGSTR_VAL_TRANSITION                                       Equ         TEXT("Transition")
REGSTR_VAL_STATICDRIVE                                      Equ         TEXT("StaticDrive")
REGSTR_VAL_LOADHI                                           Equ         TEXT("LoadHi")
REGSTR_VAL_LOADRMDRIVERS                                    Equ         TEXT("LoadRMDrivers")
REGSTR_VAL_SETUPN                                           Equ         TEXT("SetupN")
REGSTR_VAL_SETUPNPATH                                       Equ         TEXT("SetupNPath")

REGSTR_VAL_WRKGRP_FORCEMAPPING                              Equ         TEXT("WrkgrpForceMapping")
REGSTR_VAL_WRKGRP_REQUIRED                                  Equ         TEXT("WrkgrpRequired")

REGSTR_PATH_CURRENT_CONTROL_SET                             Equ         TEXT("System\CurrentControlSet\Control")
REGSTR_VAL_CURRENT_USER                                     Equ         TEXT("Current User")

REGSTR_PATH_PWDPROVIDER                                     Equ         TEXT("System\CurrentControlSet\Control\PwdProvider")
REGSTR_VAL_PWDPROVIDER_PATH                                 Equ         TEXT("ProviderPath")
REGSTR_VAL_PWDPROVIDER_DESC                                 Equ         TEXT("Description")
REGSTR_VAL_PWDPROVIDER_CHANGEPWD                            Equ         TEXT("ChangePassword")
REGSTR_VAL_PWDPROVIDER_CHANGEPWDHWND                        Equ         TEXT("ChangePasswordHwnd")
REGSTR_VAL_PWDPROVIDER_GETPWDSTATUS                         Equ         TEXT("GetPasswordStatus")
REGSTR_VAL_PWDPROVIDER_ISNP                                 Equ         TEXT("NetworkProvider")
REGSTR_VAL_PWDPROVIDER_CHANGEORDER                          Equ         TEXT("ChangeOrder")

REGSTR_PATH_POLICIES                                        Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Policies")

REGSTR_PATH_UPDATE                                          Equ         TEXT("System\CurrentControlSet\Control\Update")
REGSTR_VALUE_ENABLE                                         Equ         TEXT("Enable")
REGSTR_VALUE_VERBOSE                                        Equ         TEXT("Verbose")
REGSTR_VALUE_NETPATH                                        Equ         TEXT("NetworkPath")
REGSTR_VALUE_DEFAULTLOC                                     Equ         TEXT("UseDefaultNetLocation")

REGSTR_KEY_NETWORK                                          Equ         TEXT("Network")
REGSTR_KEY_SYSTEM                                           Equ         TEXT("System")
REGSTR_KEY_PRINTERS                                         Equ         TEXT("Printers")
REGSTR_KEY_WINOLDAPP                                        Equ         TEXT("WinOldApp")
REGSTR_KEY_EXPLORER                                         Equ         TEXT("Explorer")

REGSTR_PATH_RUN_POLICY                                      Equ         REGSTR_PATH_POLICIES TEXT("\Explorer\Run")

REGSTR_VAL_NOFILESHARING                                    Equ         TEXT("NoFileSharing")
REGSTR_VAL_NOPRINTSHARING                                   Equ         TEXT("NoPrintSharing")
REGSTR_VAL_NOFILESHARINGCTRL                                Equ         TEXT("NoFileSharingControl")
REGSTR_VAL_NOPRINTSHARINGCTRL                               Equ         TEXT("NoPrintSharingControl")
REGSTR_VAL_HIDESHAREPWDS                                    Equ         TEXT("HideSharePwds")
REGSTR_VAL_DISABLEPWDCACHING                                Equ         TEXT("DisablePwdCaching")
REGSTR_VAL_ALPHANUMPWDS                                     Equ         TEXT("AlphanumPwds")
REGSTR_VAL_NETSETUP_DISABLE                                 Equ         TEXT("NoNetSetup")
REGSTR_VAL_NETSETUP_NOCONFIGPAGE                            Equ         TEXT("NoNetSetupConfigPage")
REGSTR_VAL_NETSETUP_NOIDPAGE                                Equ         TEXT("NoNetSetupIDPage")
REGSTR_VAL_NETSETUP_NOSECURITYPAGE                          Equ         TEXT("NoNetSetupSecurityPage")
REGSTR_VAL_SYSTEMCPL_NOVIRTMEMPAGE                          Equ         TEXT("NoVirtMemPage")
REGSTR_VAL_SYSTEMCPL_NODEVMGRPAGE                           Equ         TEXT("NoDevMgrPage")
REGSTR_VAL_SYSTEMCPL_NOCONFIGPAGE                           Equ         TEXT("NoConfigPage")
REGSTR_VAL_SYSTEMCPL_NOFILESYSPAGE                          Equ         TEXT("NoFileSysPage")
REGSTR_VAL_DISPCPL_NODISPCPL                                Equ         TEXT("NoDispCPL")
REGSTR_VAL_DISPCPL_NOBACKGROUNDPAGE                         Equ         TEXT("NoDispBackgroundPage")
REGSTR_VAL_DISPCPL_NOSCRSAVPAGE                             Equ         TEXT("NoDispScrSavPage")
REGSTR_VAL_DISPCPL_NOAPPEARANCEPAGE                         Equ         TEXT("NoDispAppearancePage")
REGSTR_VAL_DISPCPL_NOSETTINGSPAGE                           Equ         TEXT("NoDispSettingsPage")
REGSTR_VAL_SECCPL_NOSECCPL                                  Equ         TEXT("NoSecCPL")
REGSTR_VAL_SECCPL_NOPWDPAGE                                 Equ         TEXT("NoPwdPage")
REGSTR_VAL_SECCPL_NOADMINPAGE                               Equ         TEXT("NoAdminPage")
REGSTR_VAL_SECCPL_NOPROFILEPAGE                             Equ         TEXT("NoProfilePage")
REGSTR_VAL_PRINTERS_HIDETABS                                Equ         TEXT("NoPrinterTabs")
REGSTR_VAL_PRINTERS_NODELETE                                Equ         TEXT("NoDeletePrinter")
REGSTR_VAL_PRINTERS_NOADD                                   Equ         TEXT("NoAddPrinter")
REGSTR_VAL_WINOLDAPP_DISABLED                               Equ         TEXT("Disabled")
REGSTR_VAL_WINOLDAPP_NOREALMODE                             Equ         TEXT("NoRealMode")
REGSTR_VAL_NOENTIRENETWORK                                  Equ         TEXT("NoEntireNetwork")
REGSTR_VAL_NOWORKGROUPCONTENTS                              Equ         TEXT("NoWorkgroupContents")
REGSTR_VAL_UNDOCK_WITHOUT_LOGON                             Equ         TEXT("UndockWithoutLogon")
REGSTR_VAL_MINPWDLEN                                        Equ         TEXT("MinPwdLen")
REGSTR_VAL_PWDEXPIRATION                                    Equ         TEXT("PwdExpiration")
REGSTR_VAL_WIN31PROVIDER                                    Equ         TEXT("Win31Provider")
REGSTR_VAL_DISABLEREGTOOLS                                  Equ         TEXT("DisableRegistryTools")

REGSTR_PATH_WINLOGON                                        Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Winlogon")
REGSTR_VAL_LEGALNOTICECAPTION                               Equ         TEXT("LegalNoticeCaption")
REGSTR_VAL_LEGALNOTICETEXT                                  Equ         TEXT("LegalNoticeText")
REGSTR_VAL_DRIVE_SPINDOWN                                   Equ         TEXT("NoDispSpinDown")
REGSTR_VAL_SHUTDOWN_FLAGS                                   Equ         TEXT("ShutdownFlags")
REGSTR_VAL_RESTRICTRUN                                      Equ         TEXT("RestrictRun")

REGSTR_KEY_POL_USERS                                        Equ         TEXT("Users")
REGSTR_KEY_POL_COMPUTERS                                    Equ         TEXT("Computers")
REGSTR_KEY_POL_USERGROUPS                                   Equ         TEXT("UserGroups")
REGSTR_KEY_POL_DEFAULT                                      Equ         TEXT(".default")
REGSTR_KEY_POL_USERGROUPDATA                                Equ         TEXT("GroupData\UserGroups\Priority")

REGSTR_PATH_TIMEZONE                                        Equ         TEXT("System\CurrentControlSet\Control\TimeZoneInformation")
REGSTR_VAL_TZBIAS                                           Equ         TEXT("Bias")
REGSTR_VAL_TZDLTBIAS                                        Equ         TEXT("DaylightBias")
REGSTR_VAL_TZSTDBIAS                                        Equ         TEXT("StandardBias")
REGSTR_VAL_TZACTBIAS                                        Equ         TEXT("ActiveTimeBias")
REGSTR_VAL_TZDLTFLAG                                        Equ         TEXT("DaylightFlag")
REGSTR_VAL_TZSTDSTART                                       Equ         TEXT("StandardStart")
REGSTR_VAL_TZDLTSTART                                       Equ         TEXT("DaylightStart")
REGSTR_VAL_TZDLTNAME                                        Equ         TEXT("DaylightName")
REGSTR_VAL_TZSTDNAME                                        Equ         TEXT("StandardName")
REGSTR_VAL_TZNOCHANGESTART                                  Equ         TEXT("NoChangeStart")
REGSTR_VAL_TZNOCHANGEEND                                    Equ         TEXT("NoChangeEnd")
REGSTR_VAL_TZNOAUTOTIME                                     Equ         TEXT("DisableAutoDaylightTimeSet")

REGSTR_PATH_FLOATINGPOINTPROCESSOR                          Equ         TEXT("HARDWARE\DESCRIPTION\System\FloatingPointProcessor")
REGSTR_PATH_FLOATINGPOINTPROCESSOR0                         Equ         TEXT("HARDWARE\DESCRIPTION\System\FloatingPointProcessor\0")

REGSTR_PATH_COMPUTRNAME                                     Equ         TEXT("System\CurrentControlSet\Control\ComputerName\ComputerName")
REGSTR_VAL_COMPUTRNAME                                      Equ         TEXT("ComputerName")

REGSTR_PATH_SHUTDOWN                                        Equ         TEXT("System\CurrentControlSet\Control\Shutdown")
REGSTR_VAL_FORCEREBOOT                                      Equ         TEXT("ForceReboot")
REGSTR_VAL_SETUPPROGRAMRAN                                  Equ         TEXT("SetupProgramRan")
REGSTR_VAL_DOES_POLLING                                     Equ         TEXT("PollingSupportNeeded")

REGSTR_PATH_KNOWNDLLS                                       Equ         TEXT("System\CurrentControlSet\Control\SessionManager\KnownDLLs")
REGSTR_PATH_KNOWN16DLLS                                     Equ         TEXT("System\CurrentControlSet\Control\SessionManager\Known16DLLs")
REGSTR_PATH_CHECKVERDLLS                                    Equ         TEXT("System\CurrentControlSet\Control\SessionManager\CheckVerDLLs")
REGSTR_PATH_WARNVERDLLS                                     Equ         TEXT("System\CurrentControlSet\Control\SessionManager\WarnVerDLLs")
REGSTR_PATH_HACKINIFILE                                     Equ         TEXT("System\CurrentControlSet\Control\SessionManager\HackIniFiles")
REGSTR_PATH_CHECKBADAPPS                                    Equ         TEXT("System\CurrentControlSet\Control\SessionManager\CheckBadApps")
REGSTR_PATH_APPPATCH                                        Equ         TEXT("System\CurrentControlSet\Control\SessionManager\AppPatches")
REGSTR_PATH_CHECKBADAPPS400                                 Equ         TEXT("System\CurrentControlSet\Control\SessionManager\CheckBadApps400")
REGSTR_PATH_KNOWNVXDS                                       Equ         TEXT("System\CurrentControlSet\Control\SessionManager\KnownVxDs")

REGSTR_VAL_UNINSTALLER_DISPLAYNAME                          Equ         TEXT("DisplayName")
REGSTR_VAL_UNINSTALLER_COMMANDLINE                          Equ         TEXT("UninstallString")
REGSTR_VAL_REINSTALL_DISPLAYNAME                            Equ         TEXT("DisplayName")
REGSTR_VAL_REINSTALL_STRING                                 Equ         TEXT("ReinstallString")
REGSTR_VAL_REINSTALL_DEVICEINSTANCEIDS                      Equ         TEXT("DeviceInstanceIds")

REGSTR_PATH_DESKTOP                                         Equ         REGSTR_PATH_SCREENSAVE
REGSTR_PATH_MOUSE                                           Equ         TEXT("Control Panel\Mouse")
REGSTR_PATH_KEYBOARD                                        Equ         TEXT("Control Panel\Keyboard")
REGSTR_PATH_COLORS                                          Equ         TEXT("Control Panel\Colors")
REGSTR_PATH_SOUND                                           Equ         TEXT("Control Panel\Sound")
REGSTR_PATH_METRICS                                         Equ         TEXT("Control Panel\Desktop\WindowMetrics")
REGSTR_PATH_ICONS                                           Equ         TEXT("Control Panel\Icons")
REGSTR_PATH_CURSORS                                         Equ         TEXT("Control Panel\Cursors")
REGSTR_PATH_CHECKDISK                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive")
REGSTR_PATH_CHECKDISKSET                                    Equ         TEXT("Settings")
REGSTR_PATH_CHECKDISKUDRVS                                  Equ         TEXT("NoUnknownDDErrDrvs")
REGSTR_PATH_FAULT                                           Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Fault")
REGSTR_VAL_FAULT_LOGFILE                                    Equ         TEXT("LogFile")
REGSTR_PATH_AEDEBUG                                         Equ         TEXT("Software\Microsoft\Windows NT\CurrentVersion\AeDebug")

REGSTR_VAL_AEDEBUG_DEBUGGER                                 Equ         TEXT("Debugger")
REGSTR_VAL_AEDEBUG_AUTO                                     Equ         TEXT("Auto")

REGSTR_PATH_GRPCONV                                         Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\GrpConv")

REGSTR_VAL_REGITEMDELETEMESSAGE                             Equ         TEXT("Removal Message")

REGSTR_PATH_LASTCHECK                                       Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer\LastCheck")
REGSTR_PATH_LASTOPTIMIZE                                    Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer\LastOptimize")
REGSTR_PATH_LASTBACKUP                                      Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer\LastBackup")
REGSTR_PATH_CHKLASTCHECK                                    Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastCheck")
REGSTR_PATH_CHKLASTSURFAN                                   Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastSurfaceAnalysis")

IFNDEF _IN_KERNEL_
    DSKTLSYSTEMTIME Struct
        wYear                                               DW          ?
        wMonth                                              DW          ?
        wDayOfWeek                                          DW          ?
        wDay                                                DW          ?
        wHour                                               DW          ?
        wMinute                                             DW          ?
        wSecond                                             DW          ?
        wMilliseconds                                       DW          ?
        wResult                                             DW          ?
    DSKTLSYSTEMTIME EndS
    PDSKTLSYSTEMTIME                                        TypeDef     DWord
ENDIF

DTRESULTOK                                                  Equ         0
DTRESULTFIX                                                 Equ         1
DTRESULTPROB                                                Equ         2
DTRESULTPART                                                Equ         3

REGSTR_KEY_SHARES                                           Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Network\LanMan")
REGSTR_VAL_SHARES_FLAGS                                     Equ         TEXT("Flags")
REGSTR_VAL_SHARES_TYPE                                      Equ         TEXT("Type")
REGSTR_VAL_SHARES_PATH                                      Equ         TEXT("Path")
REGSTR_VAL_SHARES_REMARK                                    Equ         TEXT("Remark")
REGSTR_VAL_SHARES_RW_PASS                                   Equ         TEXT("Parm1")
REGSTR_VAL_SHARES_RO_PASS                                   Equ         TEXT("Parm2")

REGSTR_PATH_PRINT                                           Equ         TEXT("System\CurrentControlSet\Control\Print")
REGSTR_PATH_PRINTERS                                        Equ         TEXT("System\CurrentControlSet\Control\Print\Printers")
REGSTR_PATH_PROVIDERS                                       Equ         TEXT("System\CurrentControlSet\Control\Print\Providers")
REGSTR_PATH_MONITORS                                        Equ         TEXT("System\CurrentControlSet\Control\Print\Monitors")
REGSTR_PATH_ENVIRONMENTS                                    Equ         TEXT("System\CurrentControlSet\Control\Print\Environments")
REGSTR_VAL_START_ON_BOOT                                    Equ         TEXT("StartOnBoot")
REGSTR_VAL_PRINTERS_MASK                                    Equ         TEXT("PrintersMask")
REGSTR_VAL_DOS_SPOOL_MASK                                   Equ         TEXT("DOSSpoolMask")
REGSTR_KEY_CURRENT_ENV                                      Equ         TEXT("\Windows 4.0")
REGSTR_KEY_DRIVERS                                          Equ         TEXT("\Drivers")
REGSTR_KEY_PRINT_PROC                                       Equ         TEXT("\Print Processors")

REGSTR_PATH_EVENTLABELS                                     Equ         TEXT("AppEvents\EventLabels")
REGSTR_PATH_SCHEMES                                         Equ         TEXT("AppEvents\Schemes")
REGSTR_PATH_APPS                                            Equ         TEXT("AppEvents\Schemes\Apps")
REGSTR_PATH_APPS_DEFAULT                                    Equ         TEXT("AppEvents\Schemes\Apps\.Default")
REGSTR_PATH_NAMES                                           Equ         TEXT("AppEvents\Schemes\Names")
REGSTR_PATH_MULTIMEDIA                                      Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Multimedia")
REGSTR_PATH_MULTIMEDIA_AUDIO                                Equ         TEXT("Software\Microsoft\Multimedia\Audio")
REGSTR_PATH_MULTIMEDIA_AUDIO_IMAGES                         Equ         TEXT("Software\Microsoft\Multimedia\Audio\Images")

REGSTR_PATH_MEDIARESOURCES                                  Equ         TEXT("System\CurrentControlSet\Control\MediaResources")
REGSTR_PATH_MEDIAPROPERTIES                                 Equ         TEXT("System\CurrentControlSet\Control\MediaProperties")
REGSTR_PATH_PRIVATEPROPERTIES                               Equ         TEXT("System\CurrentControlSet\Control\MediaProperties\PrivateProperties")
REGSTR_PATH_PUBLICPROPERTIES                                Equ         TEXT("System\CurrentControlSet\Control\MediaProperties\PublicProperties")

REGSTR_PATH_JOYOEM                                          Equ         TEXT("System\CurrentControlSet\Control\MediaProperties\PrivateProperties\Joystick\OEM")
REGSTR_PATH_JOYCONFIG                                       Equ         TEXT("System\CurrentControlSet\Control\MediaResources\Joystick")
REGSTR_KEY_JOYCURR                                          Equ         TEXT("CurrentJoystickSettings")
REGSTR_KEY_JOYSETTINGS                                      Equ         TEXT("JoystickSettings")

REGSTR_VAL_JOYUSERVALUES                                    Equ         TEXT("JoystickUserValues")
REGSTR_VAL_JOYCALLOUT                                       Equ         TEXT("JoystickCallout")
REGSTR_VAL_JOYNCONFIG                                       Equ         TEXT("Joystick%dConfiguration")
REGSTR_VAL_JOYNOEMNAME                                      Equ         TEXT("Joystick%dOEMName")
REGSTR_VAL_JOYNOEMCALLOUT                                   Equ         TEXT("Joystick%dOEMCallout")
REGSTR_VAL_JOYOEMCALLOUT                                    Equ         TEXT("OEMCallout")
REGSTR_VAL_JOYOEMNAME                                       Equ         TEXT("OEMName")
REGSTR_VAL_JOYOEMDATA                                       Equ         TEXT("OEMData")
REGSTR_VAL_JOYOEMXYLABEL                                    Equ         TEXT("OEMXYLabel")
REGSTR_VAL_JOYOEMZLABEL                                     Equ         TEXT("OEMZLabel")
REGSTR_VAL_JOYOEMRLABEL                                     Equ         TEXT("OEMRLabel")
REGSTR_VAL_JOYOEMPOVLABEL                                   Equ         TEXT("OEMPOVLabel")
REGSTR_VAL_JOYOEMULABEL                                     Equ         TEXT("OEMULabel")
REGSTR_VAL_JOYOEMVLABEL                                     Equ         TEXT("OEMVLabel")
REGSTR_VAL_JOYOEMTESTMOVEDESC                               Equ         TEXT("OEMTestMoveDesc")
REGSTR_VAL_JOYOEMTESTBUTTONDESC                             Equ         TEXT("OEMTestButtonDesc")
REGSTR_VAL_JOYOEMTESTMOVECAP                                Equ         TEXT("OEMTestMoveCap")
REGSTR_VAL_JOYOEMTESTBUTTONCAP                              Equ         TEXT("OEMTestButtonCap")
REGSTR_VAL_JOYOEMTESTWINCAP                                 Equ         TEXT("OEMTestWinCap")
REGSTR_VAL_JOYOEMCALCAP                                     Equ         TEXT("OEMCalCap")
REGSTR_VAL_JOYOEMCALWINCAP                                  Equ         TEXT("OEMCalWinCap")
REGSTR_VAL_JOYOEMCAL1                                       Equ         TEXT("OEMCal1")
REGSTR_VAL_JOYOEMCAL2                                       Equ         TEXT("OEMCal2")
REGSTR_VAL_JOYOEMCAL3                                       Equ         TEXT("OEMCal3")
REGSTR_VAL_JOYOEMCAL4                                       Equ         TEXT("OEMCal4")
REGSTR_VAL_JOYOEMCAL5                                       Equ         TEXT("OEMCal5")
REGSTR_VAL_JOYOEMCAL6                                       Equ         TEXT("OEMCal6")
REGSTR_VAL_JOYOEMCAL7                                       Equ         TEXT("OEMCal7")
REGSTR_VAL_JOYOEMCAL8                                       Equ         TEXT("OEMCal8")
REGSTR_VAL_JOYOEMCAL9                                       Equ         TEXT("OEMCal9")
REGSTR_VAL_JOYOEMCAL10                                      Equ         TEXT("OEMCal10")
REGSTR_VAL_JOYOEMCAL11                                      Equ         TEXT("OEMCal11")
REGSTR_VAL_JOYOEMCAL12                                      Equ         TEXT("OEMCal12")

REGSTR_VAL_AUDIO_BITMAP                                     Equ         TEXT("bitmap")
REGSTR_VAL_AUDIO_ICON                                       Equ         TEXT("icon")

REGSTR_PATH_DEVICEINSTALLER                                 Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\Device Installer")

REGSTR_PATH_DIFX                                            Equ         TEXT("Software\Microsoft\Windows\CurrentVersion\DIFX")


REGSTR_VAL_SEARCHOPTIONS                                    Equ         TEXT("SearchOptions")

IFNDEF _IN_KERNEL_
    REGSTR_PATH_BIOSINFO                                    Equ         TEXT("System\CurrentControlSet\Control\BiosInfo")
ELSE
    REGSTR_PATH_BIOSINFO                                    Equ         L("\Registry\Machine\System\CurrentControlSet\Control\BiosInfo")
ENDIF

IFNDEF _IN_KERNEL_
    REGSTR_PATH_PCIIR                                       Equ         TEXT("System\CurrentControlSet\Control\Pnp\PciIrqRouting")
    REGSTR_VAL_OPTIONS                                      Equ         TEXT("Options")
    REGSTR_VAL_STAT                                         Equ         TEXT("Status")
    REGSTR_VAL_TABLE_STAT                                   Equ         TEXT("TableStatus")
    REGSTR_VAL_MINIPORT_STAT                                Equ         TEXT("MiniportStatus")
ELSE
    REGSTR_PATH_PCIIR                                       Equ         L("\Registry\Machine\System\CurrentControlSet\Control\Pnp\PciIrqRouting")
    REGSTR_VAL_OPTIONS                                      Equ         L("Options")
    REGSTR_VAL_STAT                                         Equ         L("Status")
    REGSTR_VAL_TABLE_STAT                                   Equ         L("TableStatus")
    REGSTR_VAL_MINIPORT_STAT                                Equ         L("MiniportStatus")
ENDIF

PIR_OPTION_ENABLED                                          Equ         00000001H
PIR_OPTION_REGISTRY                                         Equ         00000002H
PIR_OPTION_MSSPEC                                           Equ         00000004H
PIR_OPTION_REALMODE                                         Equ         00000008H
PIR_OPTION_DEFAULT                                          Equ         0000000fH

PIR_STATUS_ERROR                                            Equ         00000000H
PIR_STATUS_ENABLED                                          Equ         00000001H
PIR_STATUS_DISABLED                                         Equ         00000002H
PIR_STATUS_MAX                                              Equ         00000003H

PIR_STATUS_TABLE_REGISTRY                                   Equ         00000000H
PIR_STATUS_TABLE_MSSPEC                                     Equ         00000001H
PIR_STATUS_TABLE_REALMODE                                   Equ         00000002H
PIR_STATUS_TABLE_NONE                                       Equ         00000003H
PIR_STATUS_TABLE_ERROR                                      Equ         00000004H
PIR_STATUS_TABLE_BAD                                        Equ         00000005H
PIR_STATUS_TABLE_SUCCESS                                    Equ         00000006H
PIR_STATUS_TABLE_MAX                                        Equ         00000007H

PIR_STATUS_MINIPORT_NORMAL                                  Equ         00000000H
PIR_STATUS_MINIPORT_COMPATIBLE                              Equ         00000001H
PIR_STATUS_MINIPORT_OVERRIDE                                Equ         00000002H
PIR_STATUS_MINIPORT_NONE                                    Equ         00000003H
PIR_STATUS_MINIPORT_ERROR                                   Equ         00000004H
PIR_STATUS_MINIPORT_NOKEY                                   Equ         00000005H
PIR_STATUS_MINIPORT_SUCCESS                                 Equ         00000006H
PIR_STATUS_MINIPORT_INVALID                                 Equ         00000007H
PIR_STATUS_MINIPORT_MAX                                     Equ         00000008H

REGSTR_PATH_LASTGOOD                                        Equ         TEXT("System\LastKnownGoodRecovery\LastGood")
REGSTR_PATH_LASTGOODTMP                                     Equ         TEXT("System\LastKnownGoodRecovery\LastGood.Tmp")

LASTGOOD_OPERATION                                          Equ         000000FFH
LASTGOOD_OPERATION_NOPOSTPROC                               Equ         00000000H
LASTGOOD_OPERATION_DELETE                                   Equ         00000001H

ENDIF ;REGSTR_INC
