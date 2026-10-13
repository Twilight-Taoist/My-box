
BadUse ab = new BadUse();

ab.BadMethod();

class BadUse
{
    public void BadMethod()
    {
        int x = 100;
        this.BadMethod();
    }
}
