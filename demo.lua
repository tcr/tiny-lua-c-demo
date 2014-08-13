print('[L] running a lua script')
print('[L] calling a C function. should print 5 and return 10')
print('[L] ' .. tostring(exposed_my_func(5)));
print('[L] done.')
