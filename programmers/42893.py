




def check(char):
    if ord(char)>= 97 and ord(char)<=122:
        return True

    return False


def solution(word, pages):
    infos = []
    word = word.lower()

    # page 수만큼의 정보들 넣을 list 넣기
    for i in range(len(pages)):        
        infos.append([])
    
    #infos  0 url, 1 links, 2 score, 3 linkscore
    
    # get url "content=\""
    for i in range(len(pages)):
        html = pages[i]

        part = "content=\""

        s_idx = 0
        for w in range(len(html)):
            cur = html[w:w+len(part)]

            if cur == part:
                s_idx = w+len(part)
                
                break

        e_idx = 0
        for w in range(s_idx, len(html)):
            if html[w]=="\"":
                e_idx = w
                break
        
        url = html[s_idx:e_idx]

        infos[i].append(url)

    # get links "href="
    for i in range(len(pages)):
        html = pages[i]

        part = "href=\""

        links = []
        for w in range(len(html)):
            cur = html[w:w+len(part)]

            if cur == part:
                s_idx = w+len(part)
                e_idx = 0
                for t in range(s_idx, len(html)):
                    if html[t]=="\"":
                        e_idx = t
                        break
                
                link = html[s_idx:e_idx]
                links.append(link)

        infos[i].append(links)

    # get score
    for i in range(len(pages)):
        html = pages[i]
        html = html.lower()
        for c in range(len(html)):
            if not check(html[c]):
                html = html[:c] + "." + html[c+1:]
        
        count = 0

        a = html.split(".")
        
        for w in a:
            if word==w:
                count += 1
        
        infos[i].append(count)

    # get link score
    for i in range(len(pages)):
        infos[i].append(0)
    
    for i in range(len(pages)):
        give_score = infos[i][2] / len(infos[i][1])
        
        for l in infos[i][1]:
            for t in infos:
                if t[0]==l:
                    t[3] += give_score

    max_score = -1
    ret = -1
    
    for i in range(len(infos)):
        cur_score = infos[i][2] + infos[i][3]
        if cur_score > max_score:
            max_score = cur_score
            ret = i
    
    for a in infos:
        print(a)

    return ret




if __name__ == '__main__':
    w = "bLiNd"
    ps = ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]


    print(solution(w, ps))