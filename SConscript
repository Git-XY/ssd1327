from building import *
Import('rtconfig')

cwd    = GetCurrentDir()

src1   = []
# add ssd1327 src files.
if GetDepend('PKG_USING_SSD1327'):
    src1 += Glob('src/ssd1327.c')
    src1 += Glob('src/oled.c')
if GetDepend('PKG_USING_SSD1327_SAMPLE'):
    src1 += Glob('samples/ssd1327_sample.c')
    
# add ssd1327 include path.
path1  = [cwd + '/inc']

# add src1 and include to group.
group = DefineGroup('Ssd1327', src1, depend = ['PKG_USING_SSD1327'], CPPPATH = path1)

src2   = []
# add SimpleGUI GUI src files.   
if GetDepend('PKG_USING_SSD1327'):
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Basic.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Common.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Curve.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_FontResource.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_IconResource.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Interface.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_ItemsBase.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_List.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Menu.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Notice.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_ProcessBar.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_RealtimeGraph.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_ScrollBar.c')
    src2 += Glob('SimpleGUI/GUI/src/SGUI_Text.c')
    
# add SimpleGUI GUI include path.
path2  = [cwd + 'SimpleGUI/GUI/inc']

# add src2 and include to group.
group = DefineGroup('GUI', src2, depend = ['PKG_USING_SSD1327'], CPPPATH = path2)

src3   = []
# add SimpleGUI HMI src files.   
if GetDepend('PKG_USING_SSD1327'):
    src3 += Glob('SimpleGUI/HMI/src/HMI_Engine.c')
    
 # add SimpleGUI HMI include path.
path3  = [cwd + 'SimpleGUI/HMI/inc'] 
 
# add src3 and include to group.
group = DefineGroup('HMI', src3, depend = ['PKG_USING_SSD1327'], CPPPATH = path3) 
Return('group')