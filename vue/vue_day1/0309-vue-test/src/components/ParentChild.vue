<template>
  <div>
    <h1>나</h1>
    <div>
      {{HalbeaData}}
      </div>
      <div>{{HalbeaData2}}</div>
      <button @click="chaangeHalbeaData">손자의 바꾸기</button>
  </div>
</template>

<script>
export default {
  props:["HalbeaData","HalbeaData2"],
  methods:{
    chaangeHalbeaData(){
      this.$emit("chaangeHalbeaData","손자가바꿧음");
    }
  }
}
</script>

<style>

</style>
