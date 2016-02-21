// file.c
#define SUCCESS         0
#define FAIL            1

mixed f_rmtree(string dir)
{       
        mixed *res;

        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
                return 0;

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
        
        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
                return 0;

        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
        
        res = f_rmtree(dir);
        
        return res;     
}

mixed f_cptree(string dir, string dst)
{
        mixed *res;
        
        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
                return 0;

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
        
        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
                return 0;

        res = allocate(2);
        res[0] = allocate(0);
        res[1] = allocate(0);
        
        // 2b14�п�������ķ�ʽ
        // array res = allocate(2, allocate(0));
        
        res = f_cptree(dir, dst);
        
        return res;
}

void cat(string file)
{
        if (previous_object())
                seteuid(geteuid(previous_object()));
        else
                seteuid(ROOT_UID);
        write(read_file(file));
}

void log_file(string file, string text)
{
        seteuid(ROOT_UID);
        write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
        string path, *dir;
        int i;

        if (file_size(file) != -1) return;

        seteuid(ROOT_UID);
        dir = explode(file, "/");

        if (file[strlen(file) - 1] != '/')
                // the file is refer to a file, not directory
                dir = dir[0..sizeof(dir)-2];

        path = "/";
        for (i = 0; i < sizeof(dir); i++)
        {
                path += dir[i];
                mkdir(path);
                path += "/";
        }

        dir = 0;
        seteuid(getuid());
}

string base_name(object ob)
{
#ifdef LONELY_IMPROVED
        return efun::base_name(ob);
#else        
        string file;

        if (sscanf(file_name(ob), "%s#%*d", file) == 2)
                return file;
        else
                return file_name(ob);
#endif
}

string color_filter(string content)
{
        if (! content)
                return "";

        // Foreground color
        content = replace_string(content, "$BLK$", BLK);
        content = replace_string(content, "$RED$", RED);
        content = replace_string(content, "$GRN$", GRN);
        content = replace_string(content, "$YEL$", YEL);
        content = replace_string(content, "$BLU$", BLU);
        content = replace_string(content, "$MAG$", MAG);
        content = replace_string(content, "$CYN$", CYN);
        content = replace_string(content, "$WHT$", WHT);
        content = replace_string(content, "$HIR$", HIR);
        content = replace_string(content, "$HIG$", HIG);
        content = replace_string(content, "$HIY$", HIY);
        content = replace_string(content, "$HIB$", HIB);
        content = replace_string(content, "$HIM$", HIM);
        content = replace_string(content, "$HIC$", HIC);
        content = replace_string(content, "$HIW$", HIW);
        content = replace_string(content, "$NOR$", NOR);

        // Background color
        content = replace_string(content, "$BBLK$", BBLK);
        content = replace_string(content, "$BRED$", BRED);
        content = replace_string(content, "$BGRN$", BGRN);
        content = replace_string(content, "$BYEL$", BYEL);
        content = replace_string(content, "$BBLU$", BBLU);
        content = replace_string(content, "$BMAG$", BMAG);
        content = replace_string(content, "$BCYN$", BCYN);
        content = replace_string(content, "$BWHT$", BWHT);
        content = replace_string(content, "$HBRED$", HBRED);
        content = replace_string(content, "$HBGRN$", HBGRN);
        content = replace_string(content, "$HBYEL$", HBYEL);
        content = replace_string(content, "$HBBLU$", HBBLU);
        content = replace_string(content, "$HBMAG$", HBMAG);
        content = replace_string(content, "$HBCYN$", HBCYN);
        content = replace_string(content, "$HBWHT$", HBWHT);

        content = replace_string(content, "$U$", U);
        content = replace_string(content, "$BLINK$", BLINK);
        content = replace_string(content, "$REV$", REV);
        content = replace_string(content, "$HIREV$", HIREV);
        content = replace_string(content, "$BOLD$", BOLD);

        return content;
}

void color_cat(string file)
{
        if (previous_object())
                seteuid(geteuid(previous_object()));
        else
                seteuid(ROOT_UID);

        write(color_filter(read_file(file)));
}

int file_lines(string file)
{
#ifdef LONELY_IMPROVED
        return efun::file_lines(file);
#else
        int i;
        int jmp;

        i = 65536;
        jmp = i / 2;

        while (jmp)
        {
                if (read_file(file, i, 1)) i += jmp; else
                                           i -= jmp;
                jmp /= 2;
        }

        return i - 1;
#endif
}

int is_c_file(string arg)
{
        int l;
        
        l = strlen(arg); 
        if (arg[l - 1] == 'c' && arg[l - 2] == '.') 
                return 1; 
        
        return 0; 
}
