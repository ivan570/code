def fun(s):
    try:
        s, extension = s.split(".")
        if len(extension) > 3 or len(extension) == 0:
            return False
        username, websitename = s.split("@")
        if len(username) == 0 or len(websitename) == 0:
            return False
        for i in websitename:
            if i.isalpha() or i.isdigit():
                continue
            else:
                return False
        for i in username:
            if i.isalpha() or i.isdigit() or i == '-' or i == '_':
                continue
            else:
                return False
        return True
    except:
        return False


def filter_mail(email):
    return list(filter(fun, email))


if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())

filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)
