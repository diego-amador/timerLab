################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../release.cfg 


# Each subdirectory must supply rules for building sources it contributes
configPkg/linker.cmd: ../release.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/xs" --xdcpath= xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4 -p ti.platforms.simplelink:CC3220S -r release -c "$<"
	@echo 'Finished building: $<'
	@echo ' '


