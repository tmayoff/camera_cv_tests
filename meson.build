project('camera_cv_tests', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

opencv  = dependency('opencv4', required: true)
depthai = dependency('depthai', modules: ['depthai::opencv'], required: true)

subdir('src')
