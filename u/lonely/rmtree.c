#define SUCCESS         0
#define FAIL            1

mixed f_rmtree(string dir)
{       
        mixed *res;

        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
                
        if( dir[<1] != '/' ) dir += "/";
        
        if( file_size(dir) != -2 ) return 0;

        foreach(string file in get_dir(dir))
        {
                if( file_size(dir+file) == -2 )
                        f_rmtree(dir+file);
                else if( rm(dir+file) )
                        res[SUCCESS] += ({ dir+file });
                else
                        res[FAIL] += ({ dir+file });
        }
        
        if( rmdir(dir) )
                res[SUCCESS] += ({ dir });
        else
                res[FAIL] += ({ dir });
        
        return res;
}

mixed rmtree(string dir)
{
        mixed *res;
        
        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
        
        res = f_rmtree(dir);
        
        return res;     
}

mixed f_cptree(string dir, string dst)
{
        mixed *res;
        
        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
        
        if( dir[<1] != '/' ) dir += "/";
        
        if( file_size(dir) != -2 ) return 0;
        
        if( file_size(dst) != -2 )
        {
                if( mkdir(dst) )
                        res[SUCCESS] += ({ dst });
                else
                        res[FAIL] += ({ dst });
        }
        
        foreach(string file in get_dir(dir))
        {
                if( file_size(dir+file) == -2 )
                        f_cptree(dir+file, dst+file);
                else if( cp(dir+file, dst+file) )
                        res[SUCCESS] += ({ dst+file });
                else
                        res[FAIL] += ({ dst+file });
        }
        
        return res;
}

mixed cptree(string dir, string dst)
{
        mixed *res;
        
        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
        
        // 2b14�п�������ķ�ʽ
        // array res = allocate(2, allocate(0));
        
        res = f_cptree(dir, dst);
        
        return res;
}
