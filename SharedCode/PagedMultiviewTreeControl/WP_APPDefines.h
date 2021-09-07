#if !defined(WP_APPDefines_IncludeGuard)
#define WP_APPDefines_IncludeGuard

#define		CM_INSERTCHILD				WM_APP + 10000
#define		CM_INSERTSIBLING			WM_APP + 10001
#define		CM_DELETENODE				WM_APP + 10002
#define		CM_MODIFYNODETEXT			WM_APP + 10003
#define		CM_CHANGENODECOLOR			WM_APP + 10004
#define		CM_TOGGLECONNECTINGLINES	WM_APP + 10010
#define		CM_SETCONNECTINGLINESCOLOR	WM_APP + 10011
#define		CM_SETFONT					WM_APP + 10020
#define		CM_SETDEFAULTCOLOR			WM_APP + 10021
#define		CM_SETBACKGROUNDBITMAP		WM_APP + 10022
#define		CM_TOGGLEMENUSOUND			WM_APP + 10030

#if !defined(STRCPY)
#if defined( _UNICODE )
#define STRCPY(x,y)				wcscpy(x,y)
#define	ODDCHAR					USHORT
#else
#define STRCPY(x,y)				strcpy(x,y)
#define	ODDCHAR					TCHAR
#endif
#endif

#endif
