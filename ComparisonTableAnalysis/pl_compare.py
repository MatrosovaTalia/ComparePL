from openpyxl import load_workbook

'''
   workbook - current excel table
    Don't forget to enter your table's name!

   generate_pl(letter, name)
        used to generate a new language structure from table column data
        letter - letter used for this column in the excel table
        name - language name 

   calc_best_%x%(pl)
        used to calculate %x% metric for a specified language structure
        pl - language structure

'''

workbook = load_workbook(filename="")
sheet = workbook.active

def generate_pl(letter, name):
    pl = {}
    pl["letter"] = letter
    pl["name"] = name
    pl[("%s6" % letter)] = sheet[("%s6" % letter)].value
    pl[("%s21" % letter)] = sheet[("%s21" % letter)].value
    pl[("%s22" % letter)] = sheet[("%s22" % letter)].value
    pl[("%s28" % letter)] = sheet[("%s28" % letter)].value
    pl[("%s54" % letter)] = sheet[("%s54" % letter)].value
    pl[("%s67" % letter)] = sheet[("%s67" % letter)].value
    pl[("%s68" % letter)] = sheet[("%s68" % letter)].value
    pl[("%s85" % letter)] = sheet[("%s85" % letter)].value
    pl[("%s86" % letter)] = sheet[("%s86" % letter)].value
    pl[("%s88" % letter)] = sheet[("%s88" % letter)].value
    pl[("%s89" % letter)] = sheet[("%s89" % letter)].value
    pl[("%s90" % letter)] = sheet[("%s90" % letter)].value
    pl[("%s91" % letter)] = sheet[("%s91" % letter)].value
    pl[("%s2" % letter)] = sheet[("%s2" % letter)].value
    pl[("%s3" % letter)] = sheet[("%s3" % letter)].value
    pl[("%s4" % letter)] = sheet[("%s4" % letter)].value
    pl[("%s21" % letter)] = sheet[("%s21" % letter)].value
    pl[("%s22" % letter)] = sheet[("%s22" % letter)].value
    pl[("%s23" % letter)] = sheet[("%s23" % letter)].value
    pl[("%s26" % letter)] = sheet[("%s26" % letter)].value
    pl[("%s27" % letter)] = sheet[("%s27" % letter)].value
    pl[("%s30" % letter)] = sheet[("%s30" % letter)].value
    pl[("%s47" % letter)] = sheet[("%s47" % letter)].value
    pl[("%s48" % letter)] = sheet[("%s48" % letter)].value
    pl[("%s49" % letter)] = sheet[("%s49" % letter)].value
    pl[("%s69" % letter)] = sheet[("%s69" % letter)].value
    pl[("%s73" % letter)] = sheet[("%s73" % letter)].value
    pl[("%s80" % letter)] = sheet[("%s80" % letter)].value
    pl[("%s81" % letter)] = sheet[("%s81" % letter)].value
    pl[("%s82" % letter)] = sheet[("%s82" % letter)].value
    pl[("%s87" % letter)] = sheet[("%s87" % letter)].value
    pl[("%s93" % letter)] = sheet[("%s93" % letter)].value
    pl[("%s96" % letter)] = sheet[("%s96" % letter)].value
    pl[("%s97" % letter)] = sheet[("%s97" % letter)].value
    # pl[("%s" % letter)] = sheet[("%s" % letter)].value
    return pl

##  Best for web-development?
def calc_best_web(pl):
    coef_6 = 1.0
    coef_21 = 1.0
    coef_22 = 1.0
    coef_28 = 1.0
    coef_54 = 1.0
    coef_67 = 1.0
    coef_68 = 1.0
    coef_85 = 1.0
    coef_86 = 1.0
    coef_88 = 1.0
    coef_89 = 1.0
    coef_90 = 1.0
    coef_91 = 1.0
    return (coef_6 * pl[("%s6" % pl["letter"])] + coef_21 * pl[("%s21" % pl["letter"])]
          + coef_22 * pl[("%s22" % pl["letter"])] + coef_28 * pl[("%s28" % pl["letter"])] 
          + coef_54 * pl[("%s54" % pl["letter"])] + coef_67 * pl[("%s67" % pl["letter"])] 
          + coef_68 * pl[("%s68" % pl["letter"])] + coef_85 * pl[("%s85" % pl["letter"])]
          + coef_86 * pl[("%s86" % pl["letter"])] + coef_88 * pl[("%s88" % pl["letter"])] 
          + coef_89 * pl[("%s89" % pl["letter"])] + coef_90 * pl[("%s90" % pl["letter"])] 
          + coef_91 * pl[("%s91" % pl["letter"])])

def calc_best_business(pl):
    coef_2 = 1.0
    coef_3 = 1.0
    coef_4 = 1.0
    coef_21 = 1.0
    coef_22 = 1.0
    coef_23 = 1.0
    coef_26 = 1.0
    coef_27 = 1.0
    coef_30 = 1.0
    coef_47 = 1.0
    coef_48 = 1.0
    coef_49 = 1.0
    coef_67 = 1.0
    coef_68 = 1.0
    coef_69 = 1.0
    coef_73 = 1.0
    coef_80 = 1.0
    coef_81 = 1.0
    coef_82 = 1.0
    coef_85 = 1.0
    coef_87 = 1.0
    coef_88 = 1.0
    coef_89 = 1.0
    coef_90 = 1.0
    coef_93 = 1.0
    coef_96 = 1.0
    coef_97 = 1.0
    return (coef_2 * pl[("%s2" % pl["letter"])] + coef_3 * pl[("%s3" % pl["letter"])]
          + coef_4 * pl[("%s4" % pl["letter"])] + coef_21 * pl[("%s21" % pl["letter"])]
          + coef_22 * pl[("%s22" % pl["letter"])] + coef_23 * pl[("%s23" % pl["letter"])]
          + coef_26 * pl[("%s26" % pl["letter"])] + coef_26 * pl[("%s26" % pl["letter"])]
          + coef_27 * pl[("%s27" % pl["letter"])] + coef_30 * pl[("%s30" % pl["letter"])]
          + coef_47 * pl[("%s47" % pl["letter"])] + coef_48 * pl[("%s48" % pl["letter"])]
          + coef_49 * pl[("%s49" % pl["letter"])] + coef_67 * pl[("%s67" % pl["letter"])]
          + coef_68 * pl[("%s68" % pl["letter"])] + coef_69 * pl[("%s69" % pl["letter"])]
          + coef_73 * pl[("%s73" % pl["letter"])] + coef_80 * pl[("%s80" % pl["letter"])]
          + coef_81 * pl[("%s81" % pl["letter"])] + coef_82 * pl[("%s82" % pl["letter"])]
          + coef_85 * pl[("%s85" % pl["letter"])] + coef_87 * pl[("%s87" % pl["letter"])]
          + coef_88 * pl[("%s88" % pl["letter"])] + coef_89 * pl[("%s89" % pl["letter"])]
          + coef_90 * pl[("%s90" % pl["letter"])] + coef_93 * pl[("%s93" % pl["letter"])]
          + coef_96 * pl[("%s96" % pl["letter"])] + coef_97 * pl[("%s97" % pl["letter"])])


js = generate_pl("D", "JavaScript")
swift = generate_pl("E", "Swift")
kotlin = generate_pl("F", "Kotlin")
java = generate_pl("G", "Java")
go = generate_pl("H", "Go")
c = generate_pl("I", "C")
dart = generate_pl("J", "Dart")
rust = generate_pl("K", "Rust")
cpp = generate_pl("L", "C++")

pl_list = [js, swift, kotlin, java, go, c, dart, rust, cpp]
print("Printing baseline metrics for test:")
print("-----------------------------------")
print("Scores for web:")
print("-----------------------------------")
for pl in pl_list:
    print ("%s - %.3f" % (pl["name"], calc_best_web(pl)))

print("-----------------------------------")

print("Scores for business:") 
print("-----------------------------------")   
for pl in pl_list:    
    print ("%s - %.3f" % (pl["name"], calc_best_business(pl)))



