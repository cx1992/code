bool isMatch(char* s, char* p) {
    if(s==NULL||p==NULL)
        return false;
    if(*p=='\0')
        return *s=='\0';
    if(*(p+1)!='*')
        return ((*s==*p)||(*p=='.'&&*s!='\0'))&&isMatch(s+1,p+1);
    while((*s==*p)||(*p=='.'&&*s!='\0'))
        if(isMatch(s++,p+2))
            return true;
    return isMatch(s,p+2);
}