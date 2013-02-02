VERSION = '0.0.1'
APPNAME = 'HammingDistance'

top = '.'
out = 'build'

def options(opt):
  opt.load('compiler_cxx')

def configure(conf):
  conf.load('compiler_cxx')
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-W', '-g']

def build(bld):
  #bld.recurse('src test')
  bld.recurse('src')
