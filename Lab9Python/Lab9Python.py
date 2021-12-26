def strChange(str, k): 
    rez = ""   
    #перебір кожного слова із рядка, розбитого на слова
    for w in str.split(): 
        #конкатенація слова, коротшого за k, до рядка результату
        if len(w) < k: 
            rez += w + " "
    return rez

k = int(input("Уведіть граничну кількість символів: "))
str = input("Уведіть рядок символів: ")
rez = strChange(str, k)
print("Результат: " + rez)
