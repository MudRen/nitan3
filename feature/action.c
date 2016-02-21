// action.c
// From ES2
// Adapted for XKX

nosave mixed busy, interrupt;
nosave int p_busy;
nosave mapping override;

nomask void start_p_busy(int n)
{
        object me;
        
        if (! objectp(me = this_object())) 
                return;
        
        if (! intp(n))
                return;

        if (p_busy)
                p_busy += n;
        else
                p_busy = n;
                
        set_heart_beat(1);
}
// This is called by char' heart_beat()
nomask void continue_p_busy()
{
        if (p_busy < 0)
                p_busy = 0;
        else 
        if (p_busy > 0)
                --p_busy;
}

nomask mixed query_p_busy() { return p_busy; }
nomask int is_p_busy() { return p_busy > 0; }
nomask void stop_p_busy() { p_busy = 0; }

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        object me, ob;
        int    hubo;
        int    reduce, avoid, add;

        if (! new_busy) return;
        if (! intp(new_busy) && ! functionp(new_busy))
                error("action: Invalid busy action type.\n");

        if (! objectp(me = this_object())) return;
        if (intp(new_busy))
        {
                if (functionp(busy))
                        error("action: busy conflit.\n");

                avoid = me->query_temp("apply/avoid_busy");
                reduce = me->query_temp("apply/reduce_busy");

                if (objectp(ob = me->query_temp("last_opponent")) && 
                    me->is_fighting(ob) && 
                    (add = ob->query_temp("apply/add_busy")) > 0)
                        new_busy += add;

                if (me == this_player() &&
                    (hubo = me->query_skill("zuoyou-hubo", 1) / 30) >= 5)
                {
                        if (hubo > 10) hubo = 10;
                        new_busy -= 1 + random(hubo - 4);
                        if (new_busy < 1) new_busy = 1;
                }
                
                if (new_busy > 1 && random(10) < 4 &&
                    me->query("character") == "������")
                        new_busy--;

                if (new_busy > 1 && reduce > 0)
                {
                        new_busy -= reduce;
                        if (new_busy < 1) new_busy = 1;
                }

                if (random(100) < avoid)
                        new_busy = 1;
        }

        busy = new_busy;
        if (! intp(new_interrupt) && ! functionp(new_interrupt))
                error("action: Invalid busy action interrupt handler type.\n");
        interrupt = new_interrupt;
        set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy != 0; }
nomask void stop_busy() { busy = 0; }

// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
void continue_action()
{
        if (intp(busy) && (busy > 0))
        {
                busy--;
                return;
        } else
        if (functionp(busy))
        {
                if (! evaluate(busy, this_object()))
                {
                        busy = 0;
                        interrupt = 0;
                }
        } else
        {
                busy = 0;
                interrupt = 0;
        }
}

void interrupt_me(object who, mixed how)
{
        mixed bak;

        bak = busy;
        busy = 0;

        if (! bak) return;

        if (intp(bak) && intp(interrupt))
        {
                if (bak < interrupt || who != this_object())
                        return;

                if (intp(how) && how > 0)
                {
                        // reduce busy
                        bak -= how;
                        if (bak < 0) return;
                }
        } else
        if (functionp(interrupt))
        {
                if (evaluate(interrupt, this_object(), who, how))
                {
                        bak = 0;
                        interrupt = 0;
                }
        } else
        {
                bak = 0;
                interrupt = 0;
        }

        busy = bak;
}

// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
// 
// Because this could cause a serious security problem, so we need
// security check here.
int start_call_out(function fun, int delay)
{
        if (wiz_level(this_object()) > 0 || 1)
                // I won't bind the function because it will
                // cause a serious security problem.
                call_out("eval_function", delay, fun);
        else
                // if this_object() doesn't be a wizard, I will
                // bind the function, then the player doesn't
                // occur error when the function's owner be
                // destructed.
                call_out("eval_function", delay, bind(fun, this_object()));
        return 1;
}

protected void eval_function(function fun) { evaluate(fun); }

// I would let some function override the old function,
// such as the player unconcious/die ...
// It also cause a security problem, so I must check here
nomask int set_override(string index, function fun)
{
        if (! previous_object() ||
            geteuid(previous_object()) != ROOT_UID)
                return 0;

        if (! override)
                override = ([ ]);

        override[index] = bind(fun, this_object());
        return 1;
}

// only root & (admin) can called me
nomask mixed query_override(string index)
{
        if (! is_root(previous_object()))
                return 0;

        if (! index) return override;
        if (! override) return 0;
        return override[index];
}

// others call me to run the override function, when I return
// zero, the caller will run old execution continue.
nomask int run_override(string index)
{
        function fun;

        if (! override || ! functionp(fun = override[index]))
                return 0;

        map_delete(override, index);
        if (! sizeof(override)) override = 0;
        return (*fun)(this_object());
}

// remove override function
nomask void delete_override(string index)
{
        if (! override) return;
        map_delete(override, index);
        if (! sizeof(override)) override = 0;
}

