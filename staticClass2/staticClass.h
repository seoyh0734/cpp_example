class staticClass {
 public:
  static int i;
 private:
  struct static_constructor
  {
    static_constructor()
    {
      staticClass::i = 5;
    }
  };
  static static_constructor c;
};

int staticClass::i = 0;
staticClass::static_constructor staticClass::c;
