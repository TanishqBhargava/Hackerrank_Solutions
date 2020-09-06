/* Define the exception here */
/* BEGIN: unlocked */
  // Sample solution
class BadLengthException
{
    private:
        int n;
    public:
        BadLengthException(int n){this->n = n;}
        int what(){return n;}
};
/* END: unlocked */
