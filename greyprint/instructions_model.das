options indenting = 4
options remove_unused_symbols = false

module instructions_model

require instructions public
require model
require preview
require instructions_ui
require produce

[instruction_node(name="Scalar",category="Scalar operations")]
class Instruction_Scalar : Instruction
    override editing = true
    [[serialize]] value : float = 1.
    def Instruction_Scalar
        name = "Scalar"
        self->add_output("Out",TYPE_SCALAR)
    def override edit ( mode:EditMode ) : void
        NodeDragFloat(mode,id,"value",value)
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "{to_reg(outputs[0].reg)} = {to_produce(value)}"
        }]

[instruction_node(name="Add scalar",category="Scalar operations")]
class Instruction_AddScalar : Instruction
    override editing = true
    last_eval : float = 0.
    def Instruction_AddScalar
        name = "Add Scalar"
        self->add_input("In-1",TYPE_SCALAR)
        self->add_input("In-2",TYPE_SCALAR)
        self->add_output("Out",TYPE_SCALAR)
    def override edit ( mode:EditMode ) : void
        Text("-> {last_eval}")
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "{to_reg(outputs[0].reg)} = {to_reg(src_regs[0])} + {to_reg(src_regs[1])}"
        }]

[instruction_node(name="Output surface",category="Surface operations")]
class Instruction_OutputSurface : Instruction
    override flags = InstructionFlags Output
    def Instruction_OutputSurface
        name = "Output surface"
        self->add_input("In",TYPE_SURFACE)
    def override edit ( mode:EditMode ): void
        pass
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "output({to_reg(src_regs[0])})"
        }]


[instruction_node(name="Solid color",category="Surface operations")]
class Instruction_SolidColor : Instruction
    [[serialize]] size : int2 = int2(256,256)
    [[serialize]] color : float4 = float4(.5,.5,.5,1.)
    def Instruction_SolidColor
        name = "Solid color"
        self->add_output("Out",TYPE_SURFACE)
    def override edit ( mode:EditMode ): void
        NodeInputInt2(mode,id,"size",size)
        NodeColorEditor4(mode,id,"color",color)
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "create_surface({to_reg(outputs[0].reg)},{to_produce(size)})";
            "surface_gen_solid_color({to_reg(outputs[0].reg)},{to_produce(color)})"
        }]


[instruction_node(name="Gradient",category="Surface operations")]
class Instruction_Gradient : Instruction
    [[serialize]] size : int2 = int2(256,256)
    [[serialize]] top_left : float4 = float4(1.,0.,0.,1.)
    [[serialize]] top_right : float4 = float4(0.,1.,0.,1.)
    [[serialize]] bottom_left : float4 = float4(0.,0.,1.,1.)
    [[serialize]] bottom_right : float4 = float4(0.5,0.5,0.5,1.)
    def Instruction_Gradient
        name = "Gradient"
        self->add_output("Out",TYPE_SURFACE)
    def override edit ( mode:EditMode ) : void
        NodeInputInt2(mode,id,"size",size)
        NodeColorEditor4(mode,id,"top-left",top_left)
        NodeColorEditor4(mode,id,"top-right",top_right)
        NodeColorEditor4(mode,id,"bottom-left",bottom_left)
        NodeColorEditor4(mode,id,"bottom-right",bottom_right)
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "create_surface({to_reg(outputs[0].reg)},{to_produce(size)})";
            "surface_gen_gradient({to_reg(outputs[0].reg)},{to_produce(top_left)},{to_produce(top_right)},{to_produce(bottom_left)},{to_produce(bottom_right)})"
        }]

enum BlendOp
    Add
    Multiply
    Crossfade

[instruction_node(name="Blend",category="Surface operations")]
class Instruction_Blend : Instruction
    [[serialize]] size : int2 = int2(256,256)
    [[serialize]] op  : BlendOp = BlendOp Add
    def Instruction_Blend
        name = "Blend"
        self->add_input("Src",TYPE_SURFACE)
        self->add_input("Dst",TYPE_SURFACE)
        self->add_input("Factor",TYPE_SCALAR)
        self->add_output("Out",TYPE_SURFACE)
    def override edit ( mode:EditMode ) : void
        NodeInputInt2(mode,id,"size",size)
        NodeEditEnumeration(mode,id,"Operation",op)
    def override produce ( var src_regs : array<int> ): array<string>
        return <- [{string
            "create_surface({to_reg(outputs[0].reg)},{to_produce(size)})";
            "surface_blend_{op}({to_reg(outputs[0].reg)},{to_reg_surface(src_regs[0])},{to_reg_surface(src_regs[1])},{to_reg(src_regs[2],"0.5f")})"
        }]
